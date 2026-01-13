using OrderService.Domain;

namespace OrderService.Application.Ports.Outbound;

/// <summary>
/// Result of a payment processing operation.
/// </summary>
public record PaymentResult
{
    public bool Success { get; init; }
    public string? TransactionId { get; init; }
    public string? ErrorMessage { get; init; }

    public static PaymentResult SuccessResult(string transactionId)
    {
        return new PaymentResult
        {
            Success = true,
            TransactionId = transactionId
        };
    }

    public static PaymentResult FailureResult(string errorMessage)
    {
        return new PaymentResult
        {
            Success = false,
            ErrorMessage = errorMessage
        };
    }
}

/// <summary>
/// Outbound port: defines what the application needs from payment processing.
/// Implemented by adapters (real payment service, fake for testing, etc.)
/// </summary>
public interface IPaymentGateway
{
    PaymentResult ProcessPayment(Money amount, string orderId);
}
