"""
Outbound port: defines what the application needs from persistence.
"""
from abc import ABC, abstractmethod
from typing import TYPE_CHECKING, Optional

if TYPE_CHECKING:
    from domain.order import Order


class OrderRepository(ABC):
    """
    Outbound port: defines what the application needs from persistence.
    Implemented by adapters (database, in-memory, etc.)
    """
    
    @abstractmethod
    def save(self, order: 'Order') -> None:
        """
        Save an order.
        
        Args:
            order: Order to save
        """
        pass
    
    @abstractmethod
    def find_by_id(self, order_id: str) -> Optional['Order']:
        """
        Find an order by ID.
        
        Args:
            order_id: Order ID
        
        Returns:
            Order if found, None otherwise
        """
        pass
