"""
Outbound port: defines what the application needs from payment processing.
"""
from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from domain.money import Money


@dataclass
class PaymentResult:
    """Result of a payment processing operation."""
    success: bool
    transaction_id: str | None = None
    error_message: str | None = None
    
    @classmethod
    def success_result(cls, transaction_id: str) -> 'PaymentResult':
        """Create a successful payment result."""
        return cls(success=True, transaction_id=transaction_id)
    
    @classmethod
    def failure_result(cls, error_message: str) -> 'PaymentResult':
        """Create a failed payment result."""
        return cls(success=False, error_message=error_message)


class PaymentGateway(ABC):
    """
    Outbound port: defines what the application needs from payment processing.
    Implemented by adapters (real payment service, fake for testing, etc.)
    """
    
    @abstractmethod
    def process_payment(self, amount: 'Money', order_id: str) -> PaymentResult:
        """
        Process a payment.
        
        Args:
            amount: Amount to charge
            order_id: Order ID
        
        Returns:
            Payment result
        """
        pass
