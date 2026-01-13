"""Tests for adapters."""
from domain.money import Money
from domain.order import Order
from adapters.outbound.in_memory_repository import InMemoryOrderRepository
from adapters.outbound.fake_payment_gateway import FakePaymentGateway


def test_in_memory_repository_save_and_find():
    """Test saving and retrieving an order."""
    repository = InMemoryOrderRepository()
    total = Money(10000, "USD")
    order = Order("order-1", total)
    
    repository.save(order)
    
    retrieved = repository.find_by_id("order-1")
    assert retrieved is not None
    assert retrieved.id == order.id
    assert retrieved.total == order.total


def test_in_memory_repository_find_non_existent():
    """Test finding a non-existent order."""
    repository = InMemoryOrderRepository()
    retrieved = repository.find_by_id("non-existent")
    assert retrieved is None


def test_fake_payment_gateway():
    """Test fake payment gateway."""
    gateway = FakePaymentGateway()
    amount = Money(10000, "USD")
    
    result = gateway.process_payment(amount, "order-1")
    
    assert result.success is True
    assert result.transaction_id is not None
    assert result.transaction_id.startswith("txn-")
