using OrderService.Application.Ports.Inbound;
using OrderService.Application.Ports.Outbound;
using OrderService.Domain;

namespace OrderService.Application.UseCases;

/// <summary>
/// Use case: Place Order
/// Orchestrates domain objects and outbound ports to fulfill the business requirement.
/// </summary>
public class PlaceOrderUseCase : IPlaceOrderPort
{
    private readonly IOrderRepository _orderRepository;
    private readonly IPaymentGateway _paymentGateway;

    public PlaceOrderUseCase(
        IOrderRepository orderRepository,
        IPaymentGateway paymentGateway)
    {
        _orderRepository = orderRepository;
        _paymentGateway = paymentGateway;
    }

    public Order PlaceOrder(PlaceOrderCommand command)
    {
        // Create domain object
        var total = new Money(command.Amount, command.Currency);
        var order = Order.Create(total);

        // Process payment through port
        var paymentResult = _paymentGateway.ProcessPayment(total, order.Id);

        if (!paymentResult.Success)
        {
            throw new InvalidOperationException($"Payment failed: {paymentResult.ErrorMessage}");
        }

        // Mark order as paid
        order.MarkAsPaid();

        // Save through port
        _orderRepository.Save(order);

        return order;
    }
}
