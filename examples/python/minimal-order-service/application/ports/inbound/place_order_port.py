"""
Inbound port: defines how the application can be used.
"""
from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from domain.order import Order


@dataclass
class PlaceOrderCommand:
    """Command DTO for placing an order."""
    amount: int  # in cents
    currency: str


class PlaceOrderPort(ABC):
    """
    Inbound port: defines how the application can be used.
    This is the interface that adapters (REST, CLI) will call.
    """
    
    @abstractmethod
    def place_order(self, command: PlaceOrderCommand) -> 'Order':
        """
        Place an order.
        
        Args:
            command: Place order command
        
        Returns:
            Created order
        """
        pass
