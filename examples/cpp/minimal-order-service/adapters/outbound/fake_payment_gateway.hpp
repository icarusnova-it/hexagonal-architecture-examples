#ifndef ADAPTERS_OUTBOUND_FAKE_PAYMENT_GATEWAY_HPP
#define ADAPTERS_OUTBOUND_FAKE_PAYMENT_GATEWAY_HPP

#include "application/ports/outbound/payment_gateway.hpp"

namespace adapters::outbound {

/**
 * Outbound adapter: Fake implementation of PaymentGateway.
 * Always succeeds, used for testing.
 */
class FakePaymentGateway : public application::ports::outbound::PaymentGateway {
public:
    application::ports::outbound::PaymentResult processPayment(
        std::shared_ptr<domain::Money> amount,
        const std::string& orderId
    ) override;
};

} // namespace adapters::outbound

#endif // ADAPTERS_OUTBOUND_FAKE_PAYMENT_GATEWAY_HPP
