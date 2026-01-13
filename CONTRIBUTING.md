# Contributing to Hexagonal Architecture Examples

Thank you for your interest in contributing!

## Structure

This repository demonstrates Hexagonal Architecture across multiple languages:
- Java
- Go
- Python
- C++
- C#

Each example follows the same structure and implements the same use case (Order Service) to allow easy comparison.

## Adding a New Language

If you want to add a new language example:

1. Create a new directory under `examples/` with the language name
2. Follow the same structure as existing examples:
   - `domain/` - Domain entities and value objects
   - `application/` - Use cases and ports (interfaces)
   - `adapters/` - Inbound and outbound adapters
   - Tests for each layer
3. Implement the same Order Service use case
4. Add a README.md explaining how to build and run
5. Update the main README.md to include your language

## Principles

- **Keep it minimal** - Show the pattern, not a full application
- **Same use case** - All languages implement the same Order Service
- **Clear separation** - Domain and Application must not depend on adapters
- **Tests included** - Each example should have tests

## Code Style

- Follow language-specific conventions
- Add comments explaining hexagonal concepts
- Keep code simple and readable
- Focus on structure over features

## Questions?

Open an issue to discuss your contribution!
