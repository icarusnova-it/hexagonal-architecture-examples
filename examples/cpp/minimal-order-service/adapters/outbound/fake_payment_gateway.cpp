#include "adapters/outbound/fake_payment_gateway.hpp"
#include <random>
#include <sstream>
#include <iomanip>

namespace adapters::outbound {

application::ports::outbound::PaymentResult FakePaymentGateway::processPayment(
    std::shared_ptr<domain::Money> amount,
    const std::string& orderId
) {
    // Generate a fake transaction ID
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);
    
    std::ostringstream oss;
    oss << "txn-";
    for (int i = 0; i < 32; ++i) {
        oss << std::hex << dis(gen);
    }
    
    return application::ports::outbound::PaymentResult::successResult(oss.str());
}

} // namespace adapters::outbound
