# C++ Example - Minimal Order Service

This example demonstrates Hexagonal Architecture in C++.

## Structure

```
minimal-order-service/
├── domain/
│   ├── money.hpp
│   ├── money.cpp
│   ├── order.hpp
│   └── order.cpp
├── application/
│   ├── usecases/
│   │   ├── place_order_use_case.hpp
│   │   └── place_order_use_case.cpp
│   └── ports/
│       ├── inbound/
│       │   └── place_order_port.hpp
│       └── outbound/
│           ├── order_repository.hpp
│           └── payment_gateway.hpp
├── adapters/
│   ├── inbound/
│   │   └── cli/
│   │       └── order_controller.hpp
│   └── outbound/
│       ├── in_memory_repository.hpp
│       ├── in_memory_repository.cpp
│       ├── fake_payment_gateway.hpp
│       └── fake_payment_gateway.cpp
├── tests/
│   ├── test_domain.cpp
│   ├── test_usecases.cpp
│   └── test_adapters.cpp
├── CMakeLists.txt
└── main.cpp
```

## Building

```bash
mkdir build
cd build
cmake ..
make
```

## Running Tests

```bash
./test_order_service
```
