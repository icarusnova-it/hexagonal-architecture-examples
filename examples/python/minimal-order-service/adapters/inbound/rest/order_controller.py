"""
Inbound adapter: REST controller.
This is at the edge - it adapts HTTP requests to use cases.
In a real application, this would use FastAPI, Flask, etc.
"""
from dataclasses import dataclass
from application.ports.inbound.place_order_port import PlaceOrderPort, PlaceOrderCommand
from domain.order import Order


@dataclass
class PlaceOrderRequest:
    """Request DTO for placing an order."""
    amount: int
    currency: str


@dataclass
class PlaceOrderResponse:
    """Response DTO for order placement."""
    id: str
    amount: int
    currency: str
    status: str


class OrderController:
    """REST controller for order operations."""
    
    def __init__(self, place_order_port: PlaceOrderPort):
        """
        Initialize the controller.
        
        Args:
            place_order_port: Place order port
        """
        self._place_order_port = place_order_port
    
    def place_order(self, request: PlaceOrderRequest) -> PlaceOrderResponse:
        """
        Handle a place order request.
        
        Args:
            request: Place order request
        
        Returns:
            Order response
        """
        command = PlaceOrderCommand(
            amount=request.amount,
            currency=request.currency
        )
        order: Order = self._place_order_port.place_order(command)
        return PlaceOrderResponse(
            id=order.id,
            amount=order.total.amount,
            currency=order.total.currency,
            status=order.status.value
        )
