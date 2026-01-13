# Python Example - Minimal Order Service

This example demonstrates Hexagonal Architecture in Python.

## Structure

```
minimal-order-service/
├── domain/
│   ├── __init__.py
│   ├── order.py
│   └── money.py
├── application/
│   ├── __init__.py
│   ├── usecases/
│   │   ├── __init__.py
│   │   └── place_order.py
│   └── ports/
│       ├── __init__.py
│       ├── inbound/
│       │   ├── __init__.py
│       │   └── place_order_port.py
│       └── outbound/
│           ├── __init__.py
│           ├── order_repository.py
│           └── payment_gateway.py
├── adapters/
│   ├── __init__.py
│   ├── inbound/
│   │   ├── __init__.py
│   │   └── rest/
│   │       ├── __init__.py
│   │       └── order_controller.py
│   └── outbound/
│       ├── __init__.py
│       ├── in_memory_repository.py
│       └── fake_payment_gateway.py
├── tests/
│   ├── __init__.py
│   ├── test_domain.py
│   ├── test_usecases.py
│   └── test_adapters.py
├── requirements.txt
└── README.md
```

## Running

```bash
pip install -r requirements.txt
pytest tests/
```
