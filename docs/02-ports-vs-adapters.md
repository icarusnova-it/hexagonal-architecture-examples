# Ports vs Adapters

## Ports

**Ports are interfaces** that define contracts. They live in the application layer and specify:
- What operations are needed
- What data flows in/out
- NOT how they are implemented

### Types of Ports

1. **Inbound Ports (Driving)**: Define how the application can be used
   - Example: `PlaceOrderUseCase` interface
   - Implemented by: REST controllers, CLI handlers, message consumers

2. **Outbound Ports (Driven)**: Define what the application needs from outside
   - Example: `OrderRepository`, `PaymentGateway`
   - Implemented by: Database adapters, HTTP clients, file systems

## Adapters

**Adapters implement ports**. They live at the edge and handle:
- Framework-specific code
- External service communication
- Data transformation

### Types of Adapters

1. **Inbound Adapters**: Implement inbound ports
   - REST controllers
   - CLI handlers
   - Message queue consumers

2. **Outbound Adapters**: Implement outbound ports
   - Database repositories
   - HTTP clients
   - File system access

## Example

```java
// PORT (interface in application layer)
interface OrderRepository {
    void save(Order order);
    Order findById(String id);
}

// ADAPTER (implementation in adapters layer)
class InMemoryOrderRepository implements OrderRepository {
    private Map<String, Order> orders = new HashMap<>();
    
    public void save(Order order) {
        orders.put(order.getId(), order);
    }
    
    public Order findById(String id) {
        return orders.get(id);
    }
}
```

## Key Principle

**Ports define WHAT, Adapters define HOW.**
