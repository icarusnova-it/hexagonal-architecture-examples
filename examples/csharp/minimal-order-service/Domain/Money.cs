namespace OrderService.Domain;

/// <summary>
/// Value object representing money.
/// Immutable and validated.
/// </summary>
public sealed class Money
{
    private readonly long _amount; // in cents
    private readonly string _currency;

    public Money(long amount, string currency)
    {
        if (amount < 0)
        {
            throw new ArgumentException("Amount cannot be negative", nameof(amount));
        }
        if (string.IsNullOrWhiteSpace(currency))
        {
            throw new ArgumentException("Currency cannot be null or empty", nameof(currency));
        }
        
        _amount = amount;
        _currency = currency.Trim().ToUpperInvariant();
    }

    public long Amount => _amount;
    public string Currency => _currency;

    public Money Add(Money other)
    {
        if (_currency != other._currency)
        {
            throw new ArgumentException("Cannot add different currencies");
        }
        return new Money(_amount + other._amount, _currency);
    }

    public override bool Equals(object? obj)
    {
        if (obj is Money other)
        {
            return _amount == other._amount && _currency == other._currency;
        }
        return false;
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(_amount, _currency);
    }

    public override string ToString()
    {
        return $"{_amount / 100.0:F2} {_currency}";
    }
}
