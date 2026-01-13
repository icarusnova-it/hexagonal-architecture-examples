# ADR 0002: Ports are Interfaces

## Status
Accepted

## Context
In Hexagonal Architecture, ports define contracts. We need to decide how to represent ports in code.

## Decision
**Ports are interfaces** (or equivalent language construct):
- Java: `interface`
- Go: `interface`
- Python: `Protocol` (typing) or ABC
- C++: Abstract class or concept
- C#: `interface`

Ports live in the **application layer**, not in adapters.

## Consequences
- ✅ Clear separation of contract from implementation
- ✅ Easy to create fake adapters for testing
- ✅ Language-idiomatic approach
- ✅ Compile-time checking (where supported)

## Example

```java
// Port (interface in application layer)
public interface OrderRepository {
    void save(Order order);
    Order findById(String id);
}

// Adapter (implementation in adapters layer)
public class InMemoryOrderRepository implements OrderRepository {
    // implementation
}
```
