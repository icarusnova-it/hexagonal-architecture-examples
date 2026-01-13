"""
Value object representing money.
Immutable and validated.
"""
from typing import Final


class Money:
    """Value object representing money."""
    
    def __init__(self, amount: int, currency: str):
        """
        Create a Money value object.
        
        Args:
            amount: Amount in cents (must be non-negative)
            currency: Currency code (must not be empty)
        
        Raises:
            ValueError: If amount is negative or currency is empty
        """
        if amount < 0:
            raise ValueError("Amount cannot be negative")
        if not currency or not currency.strip():
            raise ValueError("Currency cannot be empty")
        
        self._amount: Final[int] = amount
        self._currency: Final[str] = currency.strip().upper()
    
    @property
    def amount(self) -> int:
        """Get the amount in cents."""
        return self._amount
    
    @property
    def currency(self) -> str:
        """Get the currency code."""
        return self._currency
    
    def add(self, other: 'Money') -> 'Money':
        """
        Add two Money values.
        
        Args:
            other: Another Money value to add
        
        Returns:
            New Money value with the sum
        
        Raises:
            ValueError: If currencies don't match
        """
        if self._currency != other._currency:
            raise ValueError("Cannot add different currencies")
        return Money(self._amount + other._amount, self._currency)
    
    def __eq__(self, other: object) -> bool:
        """Check equality based on amount and currency."""
        if not isinstance(other, Money):
            return False
        return self._amount == other._amount and self._currency == other._currency
    
    def __hash__(self) -> int:
        """Hash based on amount and currency."""
        return hash((self._amount, self._currency))
    
    def __repr__(self) -> str:
        """String representation."""
        return f"Money(amount={self._amount}, currency='{self._currency}')"
