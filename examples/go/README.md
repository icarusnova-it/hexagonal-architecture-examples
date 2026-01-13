# Go Example - Minimal Order Service

This example demonstrates Hexagonal Architecture in Go.

## Structure

```
minimal-order-service/
├── domain/
│   ├── order.go
│   └── money.go
├── application/
│   ├── usecases/
│   │   └── place_order.go
│   └── ports/
│       ├── inbound/
│       │   └── place_order_port.go
│       └── outbound/
│           ├── order_repository.go
│           └── payment_gateway.go
├── adapters/
│   ├── inbound/
│   │   └── rest/
│   │       └── order_controller.go
│   └── outbound/
│       ├── in_memory_repository.go
│       └── fake_payment_gateway.go
├── domain_test.go
├── application_test.go
├── adapters_test.go
└── go.mod
```

## Running

```bash
go test ./...
go build
```
