package domain

import (
	"errors"
	"github.com/google/uuid"
)

// OrderStatus represents the status of an order.
type OrderStatus string

const (
	OrderStatusPending OrderStatus = "PENDING"
	OrderStatusPaid   OrderStatus = "PAID"
)

// Order represents a domain entity.
type Order struct {
	id     string
	total  *Money
	status OrderStatus
}

// NewOrder creates a new Order with the given ID and total.
func NewOrder(id string, total *Money) (*Order, error) {
	if id == "" {
		return nil, errors.New("order ID cannot be empty")
	}
	if total == nil {
		return nil, errors.New("total cannot be nil")
	}
	return &Order{
		id:     id,
		total:  total,
		status: OrderStatusPending,
	}, nil
}

// CreateOrder creates a new Order with a generated ID.
func CreateOrder(total *Money) (*Order, error) {
	id := uuid.New().String()
	return NewOrder(id, total)
}

// ID returns the order ID.
func (o *Order) ID() string {
	return o.id
}

// Total returns the order total.
func (o *Order) Total() *Money {
	return o.total
}

// Status returns the order status.
func (o *Order) Status() OrderStatus {
	return o.status
}

// MarkAsPaid marks the order as paid.
func (o *Order) MarkAsPaid() error {
	if o.status != OrderStatusPending {
		return errors.New("only pending orders can be marked as paid")
	}
	o.status = OrderStatusPaid
	return nil
}
