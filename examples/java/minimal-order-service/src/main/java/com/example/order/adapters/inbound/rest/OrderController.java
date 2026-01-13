package com.example.order.adapters.inbound.rest;

import com.example.order.application.ports.inbound.PlaceOrderCommand;
import com.example.order.application.ports.inbound.PlaceOrderPort;
import com.example.order.domain.Order;

/**
 * Inbound adapter: REST controller.
 * This is at the edge - it adapts HTTP requests to use cases.
 * In a real application, this would use Spring, JAX-RS, etc.
 */
public class OrderController {
    private final PlaceOrderPort placeOrderPort;

    public OrderController(PlaceOrderPort placeOrderPort) {
        this.placeOrderPort = placeOrderPort;
    }

    public OrderResponse placeOrder(PlaceOrderRequest request) {
        PlaceOrderCommand command = new PlaceOrderCommand(
            request.getAmount(),
            request.getCurrency()
        );
        Order order = placeOrderPort.placeOrder(command);
        return new OrderResponse(
            order.getId(),
            order.getTotal().getAmount(),
            order.getTotal().getCurrency(),
            order.getStatus().name()
        );
    }
}

// DTOs for REST layer
class PlaceOrderRequest {
    private long amount;
    private String currency;

    public long getAmount() {
        return amount;
    }

    public void setAmount(long amount) {
        this.amount = amount;
    }

    public String getCurrency() {
        return currency;
    }

    public void setCurrency(String currency) {
        this.currency = currency;
    }
}

class OrderResponse {
    private String id;
    private long amount;
    private String currency;
    private String status;

    public OrderResponse(String id, long amount, String currency, String status) {
        this.id = id;
        this.amount = amount;
        this.currency = currency;
        this.status = status;
    }

    public String getId() {
        return id;
    }

    public long getAmount() {
        return amount;
    }

    public String getCurrency() {
        return currency;
    }

    public String getStatus() {
        return status;
    }
}
