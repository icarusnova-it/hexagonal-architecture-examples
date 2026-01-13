#include <iostream>
#include <memory>
#include <exception>
#include "application/usecases/place_order_use_case.hpp"
#include "adapters/outbound/in_memory_repository.hpp"
#include "adapters/outbound/fake_payment_gateway.hpp"
#include "adapters/inbound/cli/order_controller.hpp"

int main() {
    std::cout << "Order Service - Hexagonal Architecture Example\n";
    std::cout << "===============================================\n\n";
    
    // Wire dependencies
    auto repository = std::make_shared<adapters::outbound::InMemoryOrderRepository>();
    auto paymentGateway = std::make_shared<adapters::outbound::FakePaymentGateway>();
    auto useCase = std::make_shared<application::usecases::PlaceOrderUseCase>(
        repository, paymentGateway
    );
    adapters::inbound::cli::OrderController controller(useCase);
    
    // Place an order
    adapters::inbound::cli::PlaceOrderRequest request{10000, "USD"};
    try {
        auto response = controller.placeOrder(request);
        std::cout << "Order placed successfully!\n";
        std::cout << "  ID: " << response.id << "\n";
        std::cout << "  Amount: " << response.amount << " cents\n";
        std::cout << "  Currency: " << response.currency << "\n";
        std::cout << "  Status: " << response.status << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}
