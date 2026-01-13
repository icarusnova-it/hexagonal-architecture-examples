#ifndef APPLICATION_PORTS_INBOUND_PLACE_ORDER_PORT_HPP
#define APPLICATION_PORTS_INBOUND_PLACE_ORDER_PORT_HPP

#include <memory>
#include <string>

namespace domain {
    class Order;
}

namespace application::ports::inbound {

struct PlaceOrderCommand {
    int64_t amount;
    std::string currency;
};

/**
 * Inbound port: defines how the application can be used.
 * This is the interface that adapters (REST, CLI) will call.
 */
class PlaceOrderPort {
public:
    virtual ~PlaceOrderPort() = default;
    virtual std::unique_ptr<domain::Order> placeOrder(const PlaceOrderCommand& command) = 0;
};

} // namespace application::ports::inbound

#endif // APPLICATION_PORTS_INBOUND_PLACE_ORDER_PORT_HPP
