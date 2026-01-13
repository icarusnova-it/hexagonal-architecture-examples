using Xunit;
using OrderService.Domain;

namespace OrderService.Tests;

public class DomainTests
{
    [Fact]
    public void ShouldCreateMoneyWithValidAmountAndCurrency()
    {
        var money = new Money(10000, "USD");
        Assert.Equal(10000, money.Amount);
        Assert.Equal("USD", money.Currency);
    }

    [Fact]
    public void ShouldThrowExceptionForNegativeAmount()
    {
        Assert.Throws<ArgumentException>(() => new Money(-100, "USD"));
    }

    [Fact]
    public void ShouldThrowExceptionForEmptyCurrency()
    {
        Assert.Throws<ArgumentException>(() => new Money(100, ""));
    }

    [Fact]
    public void ShouldAddMoneyWithSameCurrency()
    {
        var money1 = new Money(10000, "USD");
        var money2 = new Money(5000, "USD");
        var result = money1.Add(money2);
        Assert.Equal(15000, result.Amount);
        Assert.Equal("USD", result.Currency);
    }

    [Fact]
    public void ShouldThrowExceptionWhenAddingDifferentCurrencies()
    {
        var money1 = new Money(10000, "USD");
        var money2 = new Money(5000, "EUR");
        Assert.Throws<ArgumentException>(() => money1.Add(money2));
    }

    [Fact]
    public void ShouldCreateOrderWithIdAndTotal()
    {
        var total = new Money(10000, "USD");
        var order = new Order("order-1", total);
        Assert.Equal("order-1", order.Id);
        Assert.Equal(total, order.Total);
        Assert.Equal(OrderStatus.Pending, order.Status);
    }

    [Fact]
    public void ShouldCreateOrderWithGeneratedId()
    {
        var total = new Money(10000, "USD");
        var order = Order.Create(total);
        Assert.NotNull(order.Id);
        Assert.Equal(total, order.Total);
    }

    [Fact]
    public void ShouldMarkOrderAsPaid()
    {
        var total = new Money(10000, "USD");
        var order = new Order("order-1", total);
        order.MarkAsPaid();
        Assert.Equal(OrderStatus.Paid, order.Status);
    }

    [Fact]
    public void ShouldThrowExceptionWhenMarkingNonPendingOrderAsPaid()
    {
        var total = new Money(10000, "USD");
        var order = new Order("order-1", total);
        order.MarkAsPaid();
        Assert.Throws<InvalidOperationException>(() => order.MarkAsPaid());
    }
}
