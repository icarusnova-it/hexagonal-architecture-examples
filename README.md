# Hexagonal Architecture Examples (Ports & Adapters)

This repository demonstrates Hexagonal Architecture with minimal, production-style examples across:
- Java
- Go
- Python
- C++
- C#

## Goal
Show how to structure code so the **domain and use cases** are independent from frameworks, databases, and external services.

## What you will find
- Clear separation: **Domain → Application (Use Cases) → Adapters**
- Explicit ports (interfaces/contracts)
- Small, testable examples
- Same sample use-case implemented in multiple languages for comparison

## Repository Structure
- /docs      → Concept and design guides
- /diagrams  → Architecture diagrams
- /examples  → Language-specific implementations
- /adr       → Architecture decisions

## Example Use Case
**Minimal Order Service**
- PlaceOrder use case
- OrderRepository and PaymentGateway ports
- In-memory and fake adapters
- Tests focused on domain & use cases

## Principles
- Dependency Rule: outer layers depend on inner layers
- Ports are contracts, adapters are implementations
- Keep frameworks at the edge
