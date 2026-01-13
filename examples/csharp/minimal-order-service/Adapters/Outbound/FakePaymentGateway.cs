using OrderService.Application.Ports.Outbound;
using OrderService.Domain;

namespace OrderService.Adapters.Outbound;

/// <summary>
/// Outbound adapter: Fake implementation of PaymentGateway.
/// Always succeeds, used for testing.
/// </summary>
public class FakePaymentGateway : IPaymentGateway
{
    public PaymentResult ProcessPayment(Money amount, string orderId)
    {
        // Simulate payment processing
        var transactionId = $"txn-{Guid.NewGuid()}";
        return PaymentResult.SuccessResult(transactionId);
    }
}
