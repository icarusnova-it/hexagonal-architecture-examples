#include "domain/order.hpp"
#include <random>
#include <sstream>
#include <iomanip>

namespace domain {

Order::Order(const std::string& id, std::shared_ptr<Money> total)
    : id_(id), total_(total), status_(OrderStatus::PENDING) {
    if (id.empty()) {
        throw std::invalid_argument("Order ID cannot be empty");
    }
    if (!total) {
        throw std::invalid_argument("Total cannot be null");
    }
}

std::unique_ptr<Order> Order::create(std::shared_ptr<Money> total) {
    std::string id = generateId();
    return std::make_unique<Order>(id, total);
}

void Order::markAsPaid() {
    if (status_ != OrderStatus::PENDING) {
        throw std::logic_error("Only pending orders can be marked as paid");
    }
    status_ = OrderStatus::PAID;
}

std::string Order::generateId() {
    // Simple UUID-like generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);
    
    std::ostringstream oss;
    oss << "order-";
    for (int i = 0; i < 32; ++i) {
        oss << std::hex << dis(gen);
    }
    return oss.str();
}

} // namespace domain
