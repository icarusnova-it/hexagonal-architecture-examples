"""
Domain entity representing an order.
"""
import uuid
from enum import Enum
from typing import Final
from .money import Money


class OrderStatus(Enum):
    """Order status enumeration."""
    PENDING = "PENDING"
    PAID = "PAID"


class Order:
    """Domain entity representing an order."""
    
    def __init__(self, order_id: str, total: Money):
        """
        Create an Order.
        
        Args:
            order_id: Unique order identifier
            total: Total amount as Money
        
        Raises:
            ValueError: If order_id is empty or total is None
        """
        if not order_id or not order_id.strip():
            raise ValueError("Order ID cannot be empty")
        if total is None:
            raise ValueError("Total cannot be None")
        
        self._id: Final[str] = order_id
        self._total: Final[Money] = total
        self._status: OrderStatus = OrderStatus.PENDING
    
    @classmethod
    def create(cls, total: Money) -> 'Order':
        """
        Create a new Order with a generated ID.
        
        Args:
            total: Total amount as Money
        
        Returns:
            New Order instance
        """
        order_id = str(uuid.uuid4())
        return cls(order_id, total)
    
    @property
    def id(self) -> str:
        """Get the order ID."""
        return self._id
    
    @property
    def total(self) -> Money:
        """Get the order total."""
        return self._total
    
    @property
    def status(self) -> OrderStatus:
        """Get the order status."""
        return self._status
    
    def mark_as_paid(self) -> None:
        """
        Mark the order as paid.
        
        Raises:
            ValueError: If order is not in PENDING status
        """
        if self._status != OrderStatus.PENDING:
            raise ValueError("Only pending orders can be marked as paid")
        self._status = OrderStatus.PAID
    
    def __eq__(self, other: object) -> bool:
        """Check equality based on order ID."""
        if not isinstance(other, Order):
            return False
        return self._id == other._id
    
    def __hash__(self) -> int:
        """Hash based on order ID."""
        return hash(self._id)
    
    def __repr__(self) -> str:
        """String representation."""
        return f"Order(id='{self._id}', total={self._total}, status={self._status.value})"
