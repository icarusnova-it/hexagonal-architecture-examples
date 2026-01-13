package inbound

import "github.com/example/order-service/domain"

// PlaceOrderCommand represents the command to place an order.
type PlaceOrderCommand struct {
	Amount   int64
	Currency string
}

// PlaceOrderPort is the inbound port that defines how the application can be used.
type PlaceOrderPort interface {
	PlaceOrder(command PlaceOrderCommand) (*domain.Order, error)
}
