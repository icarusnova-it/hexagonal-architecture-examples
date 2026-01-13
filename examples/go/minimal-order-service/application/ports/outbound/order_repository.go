package outbound

import "github.com/example/order-service/domain"

// OrderRepository is the outbound port for order persistence.
type OrderRepository interface {
	Save(order *domain.Order) error
	FindByID(id string) (*domain.Order, error)
}
