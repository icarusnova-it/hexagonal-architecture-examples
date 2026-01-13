package com.example.order.adapters.outbound;

import com.example.order.application.ports.outbound.OrderRepository;
import com.example.order.domain.Order;

import java.util.HashMap;
import java.util.Map;

/**
 * Outbound adapter: In-memory implementation of OrderRepository.
 * Used for testing and simple scenarios.
 */
public class InMemoryOrderRepository implements OrderRepository {
    private final Map<String, Order> orders = new HashMap<>();

    @Override
    public void save(Order order) {
        orders.put(order.getId(), order);
    }

    @Override
    public Order findById(String id) {
        return orders.get(id);
    }
}
