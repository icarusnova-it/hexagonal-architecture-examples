#include <cassert>
#include <iostream>
#include <memory>
#include "domain/money.hpp"
#include "domain/order.hpp"
#include "adapters/outbound/in_memory_repository.hpp"
#include "adapters/outbound/fake_payment_gateway.hpp"

void test_in_memory_repository() {
    adapters::outbound::InMemoryOrderRepository repository;
    auto total = std::make_shared<domain::Money>(10000, "USD");
    auto order = std::make_shared<domain::Order>("order-1", total);
    
    repository.save(order);
    
    auto retrieved = repository.findById("order-1");
    assert(retrieved != nullptr);
    assert(retrieved->id() == order->id());
    
    std::cout << "✓ test_in_memory_repository passed\n";
}

void test_fake_payment_gateway() {
    adapters::outbound::FakePaymentGateway gateway;
    auto amount = std::make_shared<domain::Money>(10000, "USD");
    
    auto result = gateway.processPayment(amount, "order-1");
    
    assert(result.success);
    assert(!result.transactionId.empty());
    assert(result.transactionId.find("txn-") == 0);
    
    std::cout << "✓ test_fake_payment_gateway passed\n";
}

int main() {
    std::cout << "Running adapter tests...\n";
    test_in_memory_repository();
    test_fake_payment_gateway();
    std::cout << "All adapter tests passed!\n";
    return 0;
}
