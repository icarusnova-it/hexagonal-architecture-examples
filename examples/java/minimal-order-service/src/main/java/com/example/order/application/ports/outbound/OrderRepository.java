package com.example.order.application.ports.outbound;

import com.example.order.domain.Order;

/**
 * Outbound port: defines what the application needs from persistence.
 * Implemented by adapters (database, in-memory, etc.)
 */
public interface OrderRepository {
    void save(Order order);
    Order findById(String id);
}
