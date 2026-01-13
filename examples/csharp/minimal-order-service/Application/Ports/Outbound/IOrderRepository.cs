using OrderService.Domain;

namespace OrderService.Application.Ports.Outbound;

/// <summary>
/// Outbound port: defines what the application needs from persistence.
/// Implemented by adapters (database, in-memory, etc.)
/// </summary>
public interface IOrderRepository
{
    void Save(Order order);
    Order? FindById(string id);
}
