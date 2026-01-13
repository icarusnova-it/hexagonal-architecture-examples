package outbound

import (
	"github.com/google/uuid"
	"github.com/example/order-service/domain"
)

// FakePaymentGateway is a fake implementation of PaymentGateway for testing.
type FakePaymentGateway struct{}

// NewFakePaymentGateway creates a new FakePaymentGateway.
func NewFakePaymentGateway() *FakePaymentGateway {
	return &FakePaymentGateway{}
}

// ProcessPayment processes a payment and always succeeds.
func (g *FakePaymentGateway) ProcessPayment(amount *domain.Money, orderID string) (*PaymentResult, error) {
	transactionID := "txn-" + uuid.New().String()
	return &PaymentResult{
		Success:       true,
		TransactionID: transactionID,
	}, nil
}
