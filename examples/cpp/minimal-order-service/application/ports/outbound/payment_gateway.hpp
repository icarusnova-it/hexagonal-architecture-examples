#ifndef APPLICATION_PORTS_OUTBOUND_PAYMENT_GATEWAY_HPP
#define APPLICATION_PORTS_OUTBOUND_PAYMENT_GATEWAY_HPP

#include <memory>
#include <string>

namespace domain {
    class Money;
}

namespace application::ports::outbound {

struct PaymentResult {
    bool success;
    std::string transactionId;
    std::string errorMessage;
    
    static PaymentResult successResult(const std::string& transactionId) {
        return PaymentResult{true, transactionId, ""};
    }
    
    static PaymentResult failureResult(const std::string& errorMessage) {
        return PaymentResult{false, "", errorMessage};
    }
};

/**
 * Outbound port: defines what the application needs from payment processing.
 * Implemented by adapters (real payment service, fake for testing, etc.)
 */
class PaymentGateway {
public:
    virtual ~PaymentGateway() = default;
    virtual PaymentResult processPayment(
        std::shared_ptr<domain::Money> amount,
        const std::string& orderId
    ) = 0;
};

} // namespace application::ports::outbound

#endif // APPLICATION_PORTS_OUTBOUND_PAYMENT_GATEWAY_HPP
