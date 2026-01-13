package outbound

import (
	"sync"
	"github.com/example/order-service/domain"
)

// InMemoryOrderRepository is an in-memory implementation of OrderRepository.
type InMemoryOrderRepository struct {
	orders map[string]*domain.Order
	mu     sync.RWMutex
}

// NewInMemoryOrderRepository creates a new InMemoryOrderRepository.
func NewInMemoryOrderRepository() *InMemoryOrderRepository {
	return &InMemoryOrderRepository{
		orders: make(map[string]*domain.Order),
	}
}

// Save saves an order.
func (r *InMemoryOrderRepository) Save(order *domain.Order) error {
	r.mu.Lock()
	defer r.mu.Unlock()
	r.orders[order.ID()] = order
	return nil
}

// FindByID finds an order by ID.
func (r *InMemoryOrderRepository) FindByID(id string) (*domain.Order, error) {
	r.mu.RLock()
	defer r.mu.RUnlock()
	order, exists := r.orders[id]
	if !exists {
		return nil, nil
	}
	return order, nil
}
