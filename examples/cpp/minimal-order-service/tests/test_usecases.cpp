#include <cassert>
#include <iostream>
#include <memory>
#include "application/usecases/place_order_use_case.hpp"
#include "application/ports/inbound/place_order_port.hpp"
#include "adapters/outbound/in_memory_repository.hpp"
#include "adapters/outbound/fake_payment_gateway.hpp"
#include "domain/order.hpp"

void test_place_order_use_case() {
    auto repository = std::make_shared<adapters::outbound::InMemoryOrderRepository>();
    auto paymentGateway = std::make_shared<adapters::outbound::FakePaymentGateway>();
    application::usecases::PlaceOrderUseCase useCase(repository, paymentGateway);
    
    application::ports::inbound::PlaceOrderCommand command{10000, "USD"};
    auto order = useCase.placeOrder(command);
    
    assert(order != nullptr);
    assert(order->status() == domain::OrderStatus::PAID);
    assert(order->total()->amount() == 10000);
    
    // Verify order was saved
    auto savedOrder = repository->findById(order->id());
    assert(savedOrder != nullptr);
    assert(savedOrder->id() == order->id());
    
    std::cout << "✓ test_place_order_use_case passed\n";
}

int main() {
    std::cout << "Running use case tests...\n";
    test_place_order_use_case();
    std::cout << "All use case tests passed!\n";
    return 0;
}
