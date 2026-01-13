"""
Outbound adapter: Fake implementation of PaymentGateway.
Always succeeds, used for testing.
"""
import uuid
from application.ports.outbound.payment_gateway import PaymentGateway, PaymentResult
from domain.money import Money


class FakePaymentGateway(PaymentGateway):
    """Fake implementation of PaymentGateway for testing."""
    
    def process_payment(self, amount: Money, order_id: str) -> PaymentResult:
        """
        Process a payment (always succeeds).
        
        Args:
            amount: Amount to charge
            order_id: Order ID
        
        Returns:
            Successful payment result
        """
        transaction_id = f"txn-{uuid.uuid4()}"
        return PaymentResult.success_result(transaction_id)
