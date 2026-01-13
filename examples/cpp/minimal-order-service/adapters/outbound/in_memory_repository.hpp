#ifndef ADAPTERS_OUTBOUND_IN_MEMORY_REPOSITORY_HPP
#define ADAPTERS_OUTBOUND_IN_MEMORY_REPOSITORY_HPP

#include "application/ports/outbound/order_repository.hpp"
#include <unordered_map>
#include <mutex>

namespace adapters::outbound {

/**
 * Outbound adapter: In-memory implementation of OrderRepository.
 * Used for testing and simple scenarios.
 */
class InMemoryOrderRepository : public application::ports::outbound::OrderRepository {
public:
    void save(std::shared_ptr<domain::Order> order) override;
    std::shared_ptr<domain::Order> findById(const std::string& id) override;

private:
    std::unordered_map<std::string, std::shared_ptr<domain::Order>> orders_;
    std::mutex mutex_;
};

} // namespace adapters::outbound

#endif // ADAPTERS_OUTBOUND_IN_MEMORY_REPOSITORY_HPP
