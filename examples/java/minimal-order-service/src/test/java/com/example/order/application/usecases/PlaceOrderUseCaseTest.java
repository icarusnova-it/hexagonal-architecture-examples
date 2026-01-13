package com.example.order.application.usecases;

import com.example.order.application.ports.inbound.PlaceOrderCommand;
import com.example.order.application.ports.outbound.PaymentResult;
import com.example.order.domain.Money;
import com.example.order.domain.Order;
import com.example.order.adapters.outbound.FakePaymentGateway;
import com.example.order.adapters.outbound.InMemoryOrderRepository;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class PlaceOrderUseCaseTest {
    @Test
    void shouldPlaceOrderSuccessfully() {
        // Arrange
        InMemoryOrderRepository repository = new InMemoryOrderRepository();
        FakePaymentGateway paymentGateway = new FakePaymentGateway();
        PlaceOrderUseCase useCase = new PlaceOrderUseCase(repository, paymentGateway);

        // Act
        PlaceOrderCommand command = new PlaceOrderCommand(10000, "USD");
        Order order = useCase.placeOrder(command);

        // Assert
        assertNotNull(order);
        assertEquals(Order.OrderStatus.PAID, order.getStatus());
        assertEquals(new Money(10000, "USD"), order.getTotal());
        
        // Verify order was saved
        Order savedOrder = repository.findById(order.getId());
        assertNotNull(savedOrder);
        assertEquals(order.getId(), savedOrder.getId());
    }
}
