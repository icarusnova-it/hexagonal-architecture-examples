package com.example.order.application.ports.inbound;

/**
 * Command DTO for placing an order.
 */
public class PlaceOrderCommand {
    private final long amount; // in cents
    private final String currency;

    public PlaceOrderCommand(long amount, String currency) {
        this.amount = amount;
        this.currency = currency;
    }

    public long getAmount() {
        return amount;
    }

    public String getCurrency() {
        return currency;
    }
}
