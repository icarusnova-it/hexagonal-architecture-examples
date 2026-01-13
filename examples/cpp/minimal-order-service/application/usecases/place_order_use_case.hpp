#ifndef APPLICATION_USECASES_PLACE_ORDER_USE_CASE_HPP
#define APPLICATION_USECASES_PLACE_ORDER_USE_CASE_HPP

#include "application/ports/inbound/place_order_port.hpp"
#include <memory>

namespace application::ports::outbound {
    class OrderRepository;
    class PaymentGateway;
}

namespace application::usecases {

/**
 * Use case: Place Order
 * Orchestrates domain objects and outbound ports to fulfill the business requirement.
 */
class PlaceOrderUseCase : public ports::inbound::PlaceOrderPort {
public:
    PlaceOrderUseCase(
        std::shared_ptr<ports::outbound::OrderRepository> orderRepository,
        std::shared_ptr<ports::outbound::PaymentGateway> paymentGateway
    );
    
    std::unique_ptr<domain::Order> placeOrder(
        const ports::inbound::PlaceOrderCommand& command
    ) override;

private:
    std::shared_ptr<ports::outbound::OrderRepository> orderRepository_;
    std::shared_ptr<ports::outbound::PaymentGateway> paymentGateway_;
};

} // namespace application::usecases

#endif // APPLICATION_USECASES_PLACE_ORDER_USE_CASE_HPP
