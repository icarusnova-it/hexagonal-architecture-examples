"""
Outbound adapter: In-memory implementation of OrderRepository.
Used for testing and simple scenarios.
"""
from typing import Optional
from application.ports.outbound.order_repository import OrderRepository
from domain.order import Order


class InMemoryOrderRepository(OrderRepository):
    """In-memory implementation of OrderRepository."""
    
    def __init__(self):
        """Initialize the repository."""
        self._orders: dict[str, Order] = {}
    
    def save(self, order: Order) -> None:
        """Save an order."""
        self._orders[order.id] = order
    
    def find_by_id(self, order_id: str) -> Optional[Order]:
        """Find an order by ID."""
        return self._orders.get(order_id)
