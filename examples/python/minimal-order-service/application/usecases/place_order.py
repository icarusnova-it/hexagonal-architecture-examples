"""
Use case: Place Order
Orchestrates domain objects and outbound ports to fulfill the business requirement.
"""
from domain.money import Money
from domain.order import Order
from application.ports.inbound.place_order_port import PlaceOrderPort, PlaceOrderCommand
from application.ports.outbound.order_repository import OrderRepository
from application.ports.outbound.payment_gateway import PaymentGateway


class PlaceOrderUseCase(PlaceOrderPort):
    """Use case: Place Order"""
    
    def __init__(
        self,
        order_repository: OrderRepository,
        payment_gateway: PaymentGateway
    ):
        """
        Initialize the use case.
        
        Args:
            order_repository: Order repository port
            payment_gateway: Payment gateway port
        """
        self._order_repository = order_repository
        self._payment_gateway = payment_gateway
    
    def place_order(self, command: PlaceOrderCommand) -> Order:
        """
        Execute the place order use case.
        
        Args:
            command: Place order command
        
        Returns:
            Created order
        
        Raises:
            ValueError: If payment fails
        """
        # Create domain object
        total = Money(command.amount, command.currency)
        order = Order.create(total)
        
        # Process payment through port
        payment_result = self._payment_gateway.process_payment(total, order.id)
        
        if not payment_result.success:
            raise ValueError(f"Payment failed: {payment_result.error_message}")
        
        # Mark order as paid
        order.mark_as_paid()
        
        # Save through port
        self._order_repository.save(order)
        
        return order
