# ADR 0001: Scope - Minimal Examples

## Status
Accepted

## Context
We want to demonstrate Hexagonal Architecture across multiple languages. The examples should be:
- Small enough to understand quickly
- Complete enough to show real patterns
- Comparable across languages

## Decision
We will implement a **Minimal Order Service** with:
- Domain: `Order` entity, `Money` value object
- Use case: `PlaceOrder`
- Ports: `OrderRepository` (outbound), `PaymentGateway` (outbound), `PlaceOrderUseCase` (inbound)
- Adapters: In-memory repository, fake payment gateway, optional REST/CLI controllers
- Tests: Domain unit tests, use case tests with fakes

## Consequences
- ✅ Simple enough to understand in 10 minutes
- ✅ Shows all key hexagonal concepts
- ✅ Easy to compare across languages
- ⚠️ Not a production-ready service (missing validation, error handling, etc.)
- ⚠️ Focus is on structure, not business complexity
