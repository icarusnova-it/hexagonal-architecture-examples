#include <cassert>
#include <iostream>
#include <memory>
#include <stdexcept>
#include "domain/money.hpp"
#include "domain/order.hpp"

void test_money_creation() {
    domain::Money money(10000, "USD");
    assert(money.amount() == 10000);
    assert(money.currency() == "USD");
    std::cout << "✓ test_money_creation passed\n";
}

void test_money_negative_amount() {
    try {
        domain::Money money(-100, "USD");
        assert(false && "Should have thrown exception");
    } catch (const std::invalid_argument&) {
        std::cout << "✓ test_money_negative_amount passed\n";
    }
}

void test_money_add() {
    domain::Money money1(10000, "USD");
    domain::Money money2(5000, "USD");
    domain::Money result = money1.add(money2);
    assert(result.amount() == 15000);
    assert(result.currency() == "USD");
    std::cout << "✓ test_money_add passed\n";
}

void test_order_creation() {
    auto total = std::make_shared<domain::Money>(10000, "USD");
    auto order = domain::Order::create(total);
    assert(!order->id().empty());
    assert(order->total()->amount() == 10000);
    assert(order->status() == domain::OrderStatus::PENDING);
    std::cout << "✓ test_order_creation passed\n";
}

void test_order_mark_as_paid() {
    auto total = std::make_shared<domain::Money>(10000, "USD");
    auto order = domain::Order::create(total);
    order->markAsPaid();
    assert(order->status() == domain::OrderStatus::PAID);
    std::cout << "✓ test_order_mark_as_paid passed\n";
}

int main() {
    std::cout << "Running domain tests...\n";
    test_money_creation();
    test_money_negative_amount();
    test_money_add();
    test_order_creation();
    test_order_mark_as_paid();
    std::cout << "All domain tests passed!\n";
    return 0;
}
