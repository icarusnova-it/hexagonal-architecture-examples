"""Tests for domain layer."""
import pytest
from domain.money import Money
from domain.order import Order, OrderStatus


def test_money_creation():
    """Test creating money with valid values."""
    money = Money(10000, "USD")
    assert money.amount == 10000
    assert money.currency == "USD"


def test_money_negative_amount():
    """Test that negative amount raises ValueError."""
    with pytest.raises(ValueError, match="Amount cannot be negative"):
        Money(-100, "USD")


def test_money_empty_currency():
    """Test that empty currency raises ValueError."""
    with pytest.raises(ValueError, match="Currency cannot be empty"):
        Money(100, "")


def test_money_add():
    """Test adding money with same currency."""
    money1 = Money(10000, "USD")
    money2 = Money(5000, "USD")
    result = money1.add(money2)
    assert result.amount == 15000
    assert result.currency == "USD"


def test_money_add_different_currencies():
    """Test that adding different currencies raises ValueError."""
    money1 = Money(10000, "USD")
    money2 = Money(5000, "EUR")
    with pytest.raises(ValueError, match="Cannot add different currencies"):
        money1.add(money2)


def test_order_creation():
    """Test creating an order."""
    total = Money(10000, "USD")
    order = Order.create(total)
    assert order.id is not None
    assert order.total == total
    assert order.status == OrderStatus.PENDING


def test_order_mark_as_paid():
    """Test marking an order as paid."""
    total = Money(10000, "USD")
    order = Order.create(total)
    order.mark_as_paid()
    assert order.status == OrderStatus.PAID


def test_order_mark_as_paid_twice():
    """Test that marking a non-pending order as paid raises ValueError."""
    total = Money(10000, "USD")
    order = Order.create(total)
    order.mark_as_paid()
    with pytest.raises(ValueError, match="Only pending orders can be marked as paid"):
        order.mark_as_paid()
