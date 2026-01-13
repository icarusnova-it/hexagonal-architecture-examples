package com.example.order.adapters.outbound;

import com.example.order.application.ports.outbound.PaymentGateway;
import com.example.order.application.ports.outbound.PaymentResult;
import com.example.order.domain.Money;

import java.util.UUID;

/**
 * Outbound adapter: Fake implementation of PaymentGateway.
 * Always succeeds, used for testing.
 */
public class FakePaymentGateway implements PaymentGateway {
    @Override
    public PaymentResult processPayment(Money amount, String orderId) {
        // Simulate payment processing
        String transactionId = "txn-" + UUID.randomUUID().toString();
        return PaymentResult.success(transactionId);
    }
}
