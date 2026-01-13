# Java Example - Minimal Order Service

This example demonstrates Hexagonal Architecture in Java.

## Structure

```
minimal-order-service/
├── src/
│   ├── main/
│   │   └── java/
│   │       └── com/
│   │           └── example/
│   │               └── order/
│   │                   ├── domain/
│   │                   │   ├── Order.java
│   │                   │   └── Money.java
│   │                   ├── application/
│   │                   │   ├── usecases/
│   │                   │   │   └── PlaceOrderUseCase.java
│   │                   │   └── ports/
│   │                   │       ├── inbound/
│   │                   │       │   └── PlaceOrderPort.java
│   │                   │       └── outbound/
│   │                   │           ├── OrderRepository.java
│   │                   │           └── PaymentGateway.java
│   │                   └── adapters/
│   │                       ├── inbound/
│   │                       │   └── rest/
│   │                       │       └── OrderController.java
│   │                       └── outbound/
│   │                           ├── InMemoryOrderRepository.java
│   │                           └── FakePaymentGateway.java
│   └── test/
│       └── java/
│           └── com/
│               └── example/
│                   └── order/
│                       ├── domain/
│                       │   ├── OrderTest.java
│                       │   └── MoneyTest.java
│                       ├── application/
│                       │   └── usecases/
│                       │       └── PlaceOrderUseCaseTest.java
│                       └── adapters/
│                           ├── InMemoryOrderRepositoryTest.java
│                           └── FakePaymentGatewayTest.java
└── pom.xml
```

## Running

```bash
mvn test
mvn compile
```
