package com.example.order.application.ports.outbound;

import com.example.order.domain.Money;

/**
 * Outbound port: defines what the application needs from payment processing.
 * Implemented by adapters (real payment service, fake for testing, etc.)
 */
public interface PaymentGateway {
    PaymentResult processPayment(Money amount, String orderId);
}
