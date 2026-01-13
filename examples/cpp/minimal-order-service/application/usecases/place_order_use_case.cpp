#include "application/usecases/place_order_use_case.hpp"
#include "application/ports/outbound/order_repository.hpp"
#include "application/ports/outbound/payment_gateway.hpp"
#include "domain/money.hpp"
#include "domain/order.hpp"
#include <stdexcept>

namespace application::usecases {

PlaceOrderUseCase::PlaceOrderUseCase(
    std::shared_ptr<ports::outbound::OrderRepository> orderRepository,
    std::shared_ptr<ports::outbound::PaymentGateway> paymentGateway
) : orderRepository_(orderRepository), paymentGateway_(paymentGateway) {
}

std::unique_ptr<domain::Order> PlaceOrderUseCase::placeOrder(
    const ports::inbound::PlaceOrderCommand& command
) {
    // Create domain object
    auto total = std::make_shared<domain::Money>(command.amount, command.currency);
    auto order = domain::Order::create(total);
    
    // Process payment through port
    auto paymentResult = paymentGateway_->processPayment(total, order->id());
    
    if (!paymentResult.success) {
        throw std::runtime_error("Payment failed: " + paymentResult.errorMessage);
    }
    
    // Mark order as paid
    order->markAsPaid();
    
    // Save through port (convert unique_ptr to shared_ptr)
    std::shared_ptr<domain::Order> orderShared = std::move(order);
    orderRepository_->save(orderShared);
    
    // Return a unique_ptr that doesn't delete (repository owns the shared_ptr)
    return std::unique_ptr<domain::Order>(orderShared.get(), [orderShared](domain::Order*) {
        // Empty deleter - shared_ptr in repository maintains ownership
    });
}

} // namespace application::usecases
