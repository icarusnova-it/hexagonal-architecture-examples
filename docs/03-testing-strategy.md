# Testing Strategy

Hexagonal Architecture makes testing easier by allowing you to use fake adapters.

## Testing Pyramid

```
        /\
       /  \  E2E Tests (real adapters)
      /____\
     /      \  Integration Tests (real adapters)
    /________\
   /          \  Unit Tests (fake adapters)
  /____________\
```

## Test Types

### 1. Domain Unit Tests
Test entities and value objects in isolation.

```java
@Test
void shouldCalculateTotalPrice() {
    Money price = new Money(100, "USD");
    Order order = new Order("order-1", price);
    assertEquals(100, order.getTotal().getAmount());
}
```

### 2. Use Case Tests (with Fake Adapters)
Test business logic with fake implementations.

```java
@Test
void shouldPlaceOrder() {
    FakeOrderRepository repo = new FakeOrderRepository();
    FakePaymentGateway gateway = new FakePaymentGateway();
    PlaceOrderUseCase useCase = new PlaceOrderUseCase(repo, gateway);
    
    Order order = useCase.execute(new PlaceOrderCommand(100, "USD"));
    
    assertNotNull(order);
    assertTrue(repo.wasSaved(order));
}
```

### 3. Adapter Tests
Test adapter implementations in isolation.

```java
@Test
void shouldSaveOrderInMemory() {
    InMemoryOrderRepository repo = new InMemoryOrderRepository();
    Order order = new Order("order-1", new Money(100, "USD"));
    
    repo.save(order);
    
    assertEquals(order, repo.findById("order-1"));
}
```

## Benefits

- **Fast**: Unit tests run quickly with fakes
- **Isolated**: Test business logic without external dependencies
- **Reliable**: No flaky tests from network/database issues
- **Clear**: Tests document expected behavior

## Fake Adapters

Fake adapters are simple in-memory implementations used for testing:
- `FakeOrderRepository`: Stores orders in a Map
- `FakePaymentGateway`: Always succeeds, records calls
