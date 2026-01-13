using OrderService.Application.Ports.Inbound;
using OrderService.Domain;

namespace OrderService.Adapters.Inbound.Rest;

/// <summary>
/// Inbound adapter: REST controller.
/// This is at the edge - it adapts HTTP requests to use cases.
/// In a real application, this would use ASP.NET Core, Minimal API, etc.
/// </summary>
public class OrderController
{
    private readonly IPlaceOrderPort _placeOrderPort;

    public OrderController(IPlaceOrderPort placeOrderPort)
    {
        _placeOrderPort = placeOrderPort;
    }

    public PlaceOrderResponse PlaceOrder(PlaceOrderRequest request)
    {
        var command = new PlaceOrderCommand(request.Amount, request.Currency);
        var order = _placeOrderPort.PlaceOrder(command);
        
        return new PlaceOrderResponse(
            order.Id,
            order.Total.Amount,
            order.Total.Currency,
            order.Status.ToString()
        );
    }
}

// DTOs for REST layer
public record PlaceOrderRequest(long Amount, string Currency);

public record PlaceOrderResponse(
    string Id,
    long Amount,
    string Currency,
    string Status
);
