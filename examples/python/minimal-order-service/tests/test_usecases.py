"""Tests for use cases."""
import pytest
from domain.order import OrderStatus
from application.usecases.place_order import PlaceOrderUseCase
from application.ports.inbound.place_order_port import PlaceOrderCommand
from adapters.outbound.in_memory_repository import InMemoryOrderRepository
from adapters.outbound.fake_payment_gateway import FakePaymentGateway


def test_place_order_use_case():
    """Test placing an order through the use case."""
    # Arrange
    repository = InMemoryOrderRepository()
    payment_gateway = FakePaymentGateway()
    use_case = PlaceOrderUseCase(repository, payment_gateway)
    
    # Act
    command = PlaceOrderCommand(amount=10000, currency="USD")
    order = use_case.place_order(command)
    
    # Assert
    assert order is not None
    assert order.status == OrderStatus.PAID
    assert order.total.amount == 10000
    assert order.total.currency == "USD"
    
    # Verify order was saved
    saved_order = repository.find_by_id(order.id)
    assert saved_order is not None
    assert saved_order.id == order.id
