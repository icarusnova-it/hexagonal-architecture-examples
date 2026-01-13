using Xunit;
using OrderService.Adapters.Outbound;
using OrderService.Domain;

namespace OrderService.Tests;

public class AdapterTests
{
    [Fact]
    public void ShouldSaveAndRetrieveOrder()
    {
        var repository = new InMemoryOrderRepository();
        var order = new Order("order-1", new Money(10000, "USD"));

        repository.Save(order);

        var retrieved = repository.FindById("order-1");
        Assert.NotNull(retrieved);
        Assert.Equal(order.Id, retrieved!.Id);
        Assert.Equal(order.Total, retrieved.Total);
    }

    [Fact]
    public void ShouldReturnNullForNonExistentOrder()
    {
        var repository = new InMemoryOrderRepository();
        var retrieved = repository.FindById("non-existent");
        Assert.Null(retrieved);
    }

    [Fact]
    public void ShouldProcessPaymentSuccessfully()
    {
        var gateway = new FakePaymentGateway();
        var amount = new Money(10000, "USD");

        var result = gateway.ProcessPayment(amount, "order-1");

        Assert.True(result.Success);
        Assert.NotNull(result.TransactionId);
        Assert.True(result.TransactionId!.StartsWith("txn-"));
    }
}
