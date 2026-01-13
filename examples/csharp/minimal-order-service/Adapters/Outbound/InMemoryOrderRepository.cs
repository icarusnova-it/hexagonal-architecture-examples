using System.Collections.Concurrent;
using OrderService.Application.Ports.Outbound;
using OrderService.Domain;

namespace OrderService.Adapters.Outbound;

/// <summary>
/// Outbound adapter: In-memory implementation of OrderRepository.
/// Used for testing and simple scenarios.
/// </summary>
public class InMemoryOrderRepository : IOrderRepository
{
    private readonly ConcurrentDictionary<string, Order> _orders = new();

    public void Save(Order order)
    {
        _orders[order.Id] = order;
    }

    public Order? FindById(string id)
    {
        return _orders.TryGetValue(id, out var order) ? order : null;
    }
}
