#include "adapters/outbound/in_memory_repository.hpp"
#include <random>
#include <sstream>
#include <iomanip>

namespace adapters::outbound {

void InMemoryOrderRepository::save(std::shared_ptr<domain::Order> order) {
    std::lock_guard<std::mutex> lock(mutex_);
    orders_[order->id()] = order;
}

std::shared_ptr<domain::Order> InMemoryOrderRepository::findById(const std::string& id) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = orders_.find(id);
    if (it != orders_.end()) {
        return it->second;
    }
    return nullptr;
}

} // namespace adapters::outbound
