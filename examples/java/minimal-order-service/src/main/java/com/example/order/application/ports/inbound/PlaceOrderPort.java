package com.example.order.application.ports.inbound;

import com.example.order.domain.Order;

/**
 * Inbound port: defines how the application can be used.
 * This is the interface that adapters (REST, CLI) will call.
 */
public interface PlaceOrderPort {
    Order placeOrder(PlaceOrderCommand command);
}
