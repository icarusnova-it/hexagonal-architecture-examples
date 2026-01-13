#ifndef ADAPTERS_INBOUND_CLI_ORDER_CONTROLLER_HPP
#define ADAPTERS_INBOUND_CLI_ORDER_CONTROLLER_HPP

#include "application/ports/inbound/place_order_port.hpp"
#include <memory>

namespace adapters::inbound::cli {

struct PlaceOrderRequest {
    int64_t amount;
    std::string currency;
};

struct PlaceOrderResponse {
    std::string id;
    int64_t amount;
    std::string currency;
    std::string status;
};

/**
 * Inbound adapter: CLI controller.
 * This is at the edge - it adapts CLI commands to use cases.
 */
class OrderController {
public:
    explicit OrderController(std::shared_ptr<application::ports::inbound::PlaceOrderPort> placeOrderPort);
    
    PlaceOrderResponse placeOrder(const PlaceOrderRequest& request);

private:
    std::shared_ptr<application::ports::inbound::PlaceOrderPort> placeOrderPort_;
};

} // namespace adapters::inbound::cli

#endif // ADAPTERS_INBOUND_CLI_ORDER_CONTROLLER_HPP
