# Folder Structure Guide

A recommended hexagonal structure:

```
project/
├── domain/
│   ├── entities/          # Business entities
│   ├── value-objects/     # Immutable value objects
│   ├── services/          # Domain services
│   └── events/            # Domain events
├── application/
│   ├── use-cases/         # Business use cases
│   ├── ports/
│   │   ├── inbound/       # Inbound ports (interfaces)
│   │   └── outbound/      # Outbound ports (interfaces)
│   └── dto/               # Data transfer objects
├── adapters/
│   ├── inbound/           # Inbound adapters
│   │   ├── rest/          # REST controllers
│   │   ├── cli/           # CLI handlers
│   │   └── messaging/     # Message consumers
│   └── outbound/          # Outbound adapters
│       ├── persistence/   # Database repositories
│       ├── http/          # HTTP clients
│       └── filesystem/    # File system access
└── bootstrap/
    ├── config/            # Configuration
    └── wiring/            # Dependency injection setup
```

## Layer Responsibilities

### Domain
- Pure business logic
- No dependencies on frameworks
- No I/O operations

### Application
- Orchestrates domain objects
- Defines ports (interfaces)
- Contains use cases

### Adapters
- Framework-specific code
- External service communication
- Implements ports

### Bootstrap
- Wires everything together
- Configuration
- Application entry point

## Rule: **Domain and Application must not import adapters/frameworks.**
