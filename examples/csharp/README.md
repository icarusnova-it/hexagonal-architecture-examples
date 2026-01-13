# C# Example - Minimal Order Service

This example demonstrates Hexagonal Architecture in C#.

## Structure

```
minimal-order-service/
├── Domain/
│   ├── Money.cs
│   └── Order.cs
├── Application/
│   ├── UseCases/
│   │   └── PlaceOrderUseCase.cs
│   └── Ports/
│       ├── Inbound/
│       │   └── IPlaceOrderPort.cs
│       └── Outbound/
│           ├── IOrderRepository.cs
│           └── IPaymentGateway.cs
├── Adapters/
│   ├── Inbound/
│   │   └── Rest/
│   │       └── OrderController.cs
│   └── Outbound/
│       ├── InMemoryOrderRepository.cs
│       └── FakePaymentGateway.cs
├── Tests/
│   ├── DomainTests.cs
│   ├── UseCaseTests.cs
│   └── AdapterTests.cs
├── OrderService.csproj
└── Program.cs
```

## Running

```bash
dotnet restore
dotnet build
dotnet test
dotnet run
```
