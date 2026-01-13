# Quick Start Guide

This repository contains complete Hexagonal Architecture examples in 5 languages. Each example implements the same **Order Service** use case for easy comparison.

## What's Included

### 📚 Documentation
- **docs/** - Concept guides and explanations
- **diagrams/** - Architecture diagrams (Mermaid)
- **adr/** - Architecture Decision Records

### 💻 Examples (5 Languages)

Each example in `examples/{language}/minimal-order-service/` includes:

#### Domain Layer
- `Money` - Value object (immutable, validated)
- `Order` - Entity with business logic

#### Application Layer
- `PlaceOrderUseCase` - Business use case
- Ports (interfaces):
  - `PlaceOrderPort` (inbound)
  - `OrderRepository` (outbound)
  - `PaymentGateway` (outbound)

#### Adapters Layer
- `InMemoryOrderRepository` - In-memory persistence
- `FakePaymentGateway` - Fake payment processor
- `OrderController` - REST/CLI adapter (varies by language)

#### Tests
- Domain unit tests
- Use case tests with fake adapters
- Adapter tests

## Running Examples

### Java
```bash
cd examples/java/minimal-order-service
mvn test
mvn compile
```

### Go
```bash
cd examples/go/minimal-order-service
go test ./...
go build
```

### Python
```bash
cd examples/python/minimal-order-service
pip install -r requirements.txt
pytest tests/
```

### C++
```bash
cd examples/cpp/minimal-order-service
mkdir build && cd build
cmake ..
make
./test_order_service
```

### C#
```bash
cd examples/csharp/minimal-order-service
dotnet restore
dotnet test
dotnet run
```

## Key Concepts Demonstrated

1. **Dependency Rule** - Outer layers depend on inner layers
2. **Ports & Adapters** - Interfaces define contracts, adapters implement them
3. **Testability** - Business logic tested with fake adapters
4. **Independence** - Domain and use cases don't depend on frameworks

## Next Steps

1. Read `docs/01-what-is-hexagonal.md` for an overview
2. Pick a language you're familiar with
3. Study the structure in `examples/{language}/`
4. Compare with other languages to see how patterns translate
5. Read `docs/04-folder-structure-guide.md` for structure details

## Questions?

- Check the documentation in `docs/`
- Review the ADRs in `adr/`
- Compare implementations across languages
