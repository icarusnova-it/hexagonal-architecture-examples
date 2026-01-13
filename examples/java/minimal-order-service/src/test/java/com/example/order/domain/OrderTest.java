package com.example.order.domain;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class OrderTest {
    @Test
    void shouldCreateOrderWithIdAndTotal() {
        Money total = new Money(10000, "USD");
        Order order = new Order("order-1", total);
        assertEquals("order-1", order.getId());
        assertEquals(total, order.getTotal());
        assertEquals(Order.OrderStatus.PENDING, order.getStatus());
    }

    @Test
    void shouldCreateOrderWithGeneratedId() {
        Money total = new Money(10000, "USD");
        Order order = Order.create(total);
        assertNotNull(order.getId());
        assertEquals(total, order.getTotal());
    }

    @Test
    void shouldMarkOrderAsPaid() {
        Money total = new Money(10000, "USD");
        Order order = new Order("order-1", total);
        order.markAsPaid();
        assertEquals(Order.OrderStatus.PAID, order.getStatus());
    }

    @Test
    void shouldThrowExceptionWhenMarkingNonPendingOrderAsPaid() {
        Money total = new Money(10000, "USD");
        Order order = new Order("order-1", total);
        order.markAsPaid();
        assertThrows(IllegalStateException.class, () -> {
            order.markAsPaid();
        });
    }
}
