package com.example.order.domain;

import java.util.Objects;
import java.util.UUID;

/**
 * Domain entity representing an order.
 */
public class Order {
    private final String id;
    private final Money total;
    private OrderStatus status;

    public Order(String id, Money total) {
        if (id == null || id.trim().isEmpty()) {
            throw new IllegalArgumentException("Order ID cannot be null or empty");
        }
        if (total == null) {
            throw new IllegalArgumentException("Total cannot be null");
        }
        this.id = id;
        this.total = total;
        this.status = OrderStatus.PENDING;
    }

    public static Order create(Money total) {
        return new Order(UUID.randomUUID().toString(), total);
    }

    public String getId() {
        return id;
    }

    public Money getTotal() {
        return total;
    }

    public OrderStatus getStatus() {
        return status;
    }

    public void markAsPaid() {
        if (this.status != OrderStatus.PENDING) {
            throw new IllegalStateException("Only pending orders can be marked as paid");
        }
        this.status = OrderStatus.PAID;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Order order = (Order) o;
        return Objects.equals(id, order.id);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }

    @Override
    public String toString() {
        return String.format("Order{id='%s', total=%s, status=%s}", id, total, status);
    }

    public enum OrderStatus {
        PENDING, PAID
    }
}
