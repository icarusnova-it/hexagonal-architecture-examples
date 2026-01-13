using OrderService.Domain;

namespace OrderService.Application.Ports.Inbound;

/// <summary>
/// Inbound port: defines how the application can be used.
/// This is the interface that adapters (REST, CLI) will call.
/// </summary>
public interface IPlaceOrderPort
{
    Order PlaceOrder(PlaceOrderCommand command);
}

/// <summary>
/// Command DTO for placing an order.
/// </summary>
public record PlaceOrderCommand(long Amount, string Currency);
