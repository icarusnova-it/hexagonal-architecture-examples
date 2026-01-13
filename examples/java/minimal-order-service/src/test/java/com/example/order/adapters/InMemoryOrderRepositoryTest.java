package com.example.order.adapters;

import com.example.order.adapters.outbound.InMemoryOrderRepository;
import com.example.order.domain.Money;
import com.example.order.domain.Order;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class InMemoryOrderRepositoryTest {
    @Test
    void shouldSaveAndRetrieveOrder() {
        InMemoryOrderRepository repository = new InMemoryOrderRepository();
        Order order = new Order("order-1", new Money(10000, "USD"));

        repository.save(order);

        Order retrieved = repository.findById("order-1");
        assertNotNull(retrieved);
        assertEquals(order.getId(), retrieved.getId());
        assertEquals(order.getTotal(), retrieved.getTotal());
    }

    @Test
    void shouldReturnNullForNonExistentOrder() {
        InMemoryOrderRepository repository = new InMemoryOrderRepository();
        Order retrieved = repository.findById("non-existent");
        assertNull(retrieved);
    }
}
