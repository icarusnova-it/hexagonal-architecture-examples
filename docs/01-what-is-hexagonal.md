# What is Hexagonal Architecture?

Hexagonal Architecture (also known as Ports & Adapters) is an architectural pattern that isolates the core business logic from external concerns.

## Core Concept

The application is represented as a **hexagon**, where:
- The **center** contains the domain and business logic
- The **edges** contain adapters that connect to the outside world
- **Ports** define the interfaces (contracts) between the center and the edges

## Key Benefits

1. **Independence**: Business logic doesn't depend on frameworks, databases, or external services
2. **Testability**: Easy to test with fake adapters
3. **Flexibility**: Swap implementations (e.g., change database) without touching business logic
4. **Clarity**: Clear boundaries between what the application does and how it does it

## The Dependency Rule

**Dependencies point inward**: Outer layers depend on inner layers, never the reverse.

```
Adapters → Ports → Use Cases → Domain
```

## Layers

1. **Domain**: Entities, value objects, domain services
2. **Application**: Use cases, ports (interfaces), DTOs
3. **Adapters**: Inbound (REST, CLI) and Outbound (DB, HTTP clients)
