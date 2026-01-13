#include "adapters/inbound/cli/order_controller.hpp"
#include "application/ports/inbound/place_order_port.hpp"
#include "domain/order.hpp"
#include <stdexcept>

namespace adapters::inbound::cli {

OrderController::OrderController(
    std::shared_ptr<application::ports::inbound::PlaceOrderPort> placeOrderPort
) : placeOrderPort_(placeOrderPort) {
}

PlaceOrderResponse OrderController::placeOrder(const PlaceOrderRequest& request) {
    application::ports::inbound::PlaceOrderCommand command{
        request.amount,
        request.currency
    };
    
    auto order = placeOrderPort_->placeOrder(command);
    if (!order) {
        throw std::runtime_error("Failed to place order");
    }
    
    return PlaceOrderResponse{
        order->id(),
        order->total()->amount(),
        order->total()->currency(),
        order->status() == domain::OrderStatus::PAID ? "PAID" : "PENDING"
    };
}

} // namespace adapters::inbound::cli
