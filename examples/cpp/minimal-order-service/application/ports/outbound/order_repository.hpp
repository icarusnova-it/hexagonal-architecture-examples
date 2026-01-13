#ifndef APPLICATION_PORTS_OUTBOUND_ORDER_REPOSITORY_HPP
#define APPLICATION_PORTS_OUTBOUND_ORDER_REPOSITORY_HPP

#include <memory>
#include <string>

namespace domain {
    class Order;
}

namespace application::ports::outbound {

/**
 * Outbound port: defines what the application needs from persistence.
 * Implemented by adapters (database, in-memory, etc.)
 */
class OrderRepository {
public:
    virtual ~OrderRepository() = default;
    virtual void save(std::shared_ptr<domain::Order> order) = 0;
    virtual std::shared_ptr<domain::Order> findById(const std::string& id) = 0;
};

} // namespace application::ports::outbound

#endif // APPLICATION_PORTS_OUTBOUND_ORDER_REPOSITORY_HPP
