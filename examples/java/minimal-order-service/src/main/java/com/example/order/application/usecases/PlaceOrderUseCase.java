package com.example.order.application.usecases;

import com.example.order.application.ports.inbound.PlaceOrderCommand;
import com.example.order.application.ports.inbound.PlaceOrderPort;
import com.example.order.application.ports.outbound.OrderRepository;
import com.example.order.application.ports.outbound.PaymentGateway;
import com.example.order.domain.Money;
import com.example.order.domain.Order;

/**
 * Use case: Place Order
 * Orchestrates domain objects and outbound ports to fulfill the business requirement.
 */
public class PlaceOrderUseCase implements PlaceOrderPort {
    private final OrderRepository orderRepository;
    private final PaymentGateway paymentGateway;

    public PlaceOrderUseCase(OrderRepository orderRepository, PaymentGateway paymentGateway) {
        this.orderRepository = orderRepository;
        this.paymentGateway = paymentGateway;
    }

    @Override
    public Order placeOrder(PlaceOrderCommand command) {
        // Create domain object
        Money total = new Money(command.getAmount(), command.getCurrency());
        Order order = Order.create(total);

        // Process payment through port
        var paymentResult = paymentGateway.processPayment(total, order.getId());

        if (!paymentResult.isSuccess()) {
            throw new RuntimeException("Payment failed: " + paymentResult.getErrorMessage());
        }

        // Mark order as paid
        order.markAsPaid();

        // Save through port
        orderRepository.save(order);

        return order;
    }
}
