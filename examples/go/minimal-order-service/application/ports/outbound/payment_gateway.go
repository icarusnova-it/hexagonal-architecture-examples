package outbound

import "github.com/example/order-service/domain"

// PaymentResult represents the result of a payment operation.
type PaymentResult struct {
	Success       bool
	TransactionID string
	ErrorMessage  string
}

// PaymentGateway is the outbound port for payment processing.
type PaymentGateway interface {
	ProcessPayment(amount *domain.Money, orderID string) (*PaymentResult, error)
}
