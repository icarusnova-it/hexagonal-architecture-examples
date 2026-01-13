using OrderService.Application.UseCases;
using OrderService.Adapters.Inbound.Rest;
using OrderService.Adapters.Outbound;

Console.WriteLine("Order Service - Hexagonal Architecture Example");
Console.WriteLine("===============================================");
Console.WriteLine();

// Wire dependencies
var repository = new InMemoryOrderRepository();
var paymentGateway = new FakePaymentGateway();
var useCase = new PlaceOrderUseCase(repository, paymentGateway);
var controller = new OrderController(useCase);

// Place an order
var request = new PlaceOrderRequest(10000, "USD");
try
{
    var response = controller.PlaceOrder(request);
    Console.WriteLine("Order placed successfully!");
    Console.WriteLine($"  ID: {response.Id}");
    Console.WriteLine($"  Amount: {response.Amount} cents");
    Console.WriteLine($"  Currency: {response.Currency}");
    Console.WriteLine($"  Status: {response.Status}");
}
catch (Exception ex)
{
    Console.WriteLine($"Error: {ex.Message}");
    Environment.Exit(1);
}
