package com.example.order.adapters;

import com.example.order.adapters.outbound.FakePaymentGateway;
import com.example.order.application.ports.outbound.PaymentResult;
import com.example.order.domain.Money;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class FakePaymentGatewayTest {
    @Test
    void shouldProcessPaymentSuccessfully() {
        FakePaymentGateway gateway = new FakePaymentGateway();
        Money amount = new Money(10000, "USD");

        PaymentResult result = gateway.processPayment(amount, "order-1");

        assertTrue(result.isSuccess());
        assertNotNull(result.getTransactionId());
        assertTrue(result.getTransactionId().startsWith("txn-"));
    }
}
