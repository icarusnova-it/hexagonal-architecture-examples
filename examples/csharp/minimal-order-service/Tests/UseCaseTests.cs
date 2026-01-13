using Xunit;
using OrderService.Application.UseCases;
using OrderService.Application.Ports.Inbound;
using OrderService.Adapters.Outbound;
using OrderService.Domain;

namespace OrderService.Tests;

public class UseCaseTests
{
    [Fact]
    public void ShouldPlaceOrderSuccessfully()
    {
        // Arrange
        var repository = new InMemoryOrderRepository();
        var paymentGateway = new FakePaymentGateway();
        var useCase = new PlaceOrderUseCase(repository, paymentGateway);

        // Act
        var command = new PlaceOrderCommand(10000, "USD");
        var order = useCase.PlaceOrder(command);

        // Assert
        Assert.NotNull(order);
        Assert.Equal(OrderStatus.Paid, order.Status);
        Assert.Equal(new Money(10000, "USD"), order.Total);

        // Verify order was saved
        var savedOrder = repository.FindById(order.Id);
        Assert.NotNull(savedOrder);
        Assert.Equal(order.Id, savedOrder!.Id);
    }
}
