namespace OrderService.Domain;

/// <summary>
/// Domain entity representing an order.
/// </summary>
public class Order
{
    private OrderStatus _status;

    public Order(string id, Money total)
    {
        if (string.IsNullOrWhiteSpace(id))
        {
            throw new ArgumentException("Order ID cannot be null or empty", nameof(id));
        }
        if (total == null)
        {
            throw new ArgumentNullException(nameof(total));
        }
        
        Id = id;
        Total = total;
        _status = OrderStatus.Pending;
    }

    public static Order Create(Money total)
    {
        var id = Guid.NewGuid().ToString();
        return new Order(id, total);
    }

    public string Id { get; }
    public Money Total { get; }
    public OrderStatus Status => _status;

    public void MarkAsPaid()
    {
        if (_status != OrderStatus.Pending)
        {
            throw new InvalidOperationException("Only pending orders can be marked as paid");
        }
        _status = OrderStatus.Paid;
    }

    public override bool Equals(object? obj)
    {
        if (obj is Order other)
        {
            return Id == other.Id;
        }
        return false;
    }

    public override int GetHashCode()
    {
        return Id.GetHashCode();
    }

    public override string ToString()
    {
        return $"Order{{Id='{Id}', Total={Total}, Status={Status}}}";
    }
}

public enum OrderStatus
{
    Pending,
    Paid
}
