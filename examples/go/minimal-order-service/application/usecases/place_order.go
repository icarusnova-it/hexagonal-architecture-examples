package usecases

import (
	"fmt"
	"github.com/example/order-service/application/ports/inbound"
	"github.com/example/order-service/application/ports/outbound"
	"github.com/example/order-service/domain"
)

// PlaceOrderUseCase implements the PlaceOrderPort.
type PlaceOrderUseCase struct {
	orderRepository outbound.OrderRepository
	paymentGateway  outbound.PaymentGateway
}

// NewPlaceOrderUseCase creates a new PlaceOrderUseCase.
func NewPlaceOrderUseCase(
	orderRepository outbound.OrderRepository,
	paymentGateway outbound.PaymentGateway,
) *PlaceOrderUseCase {
	return &PlaceOrderUseCase{
		orderRepository: orderRepository,
		paymentGateway:  paymentGateway,
	}
}

// PlaceOrder executes the place order use case.
func (uc *PlaceOrderUseCase) PlaceOrder(command inbound.PlaceOrderCommand) (*domain.Order, error) {
	// Create domain object
	total, err := domain.NewMoney(command.Amount, command.Currency)
	if err != nil {
		return nil, fmt.Errorf("invalid money: %w", err)
	}

	order, err := domain.CreateOrder(total)
	if err != nil {
		return nil, fmt.Errorf("failed to create order: %w", err)
	}

	// Process payment through port
	paymentResult, err := uc.paymentGateway.ProcessPayment(total, order.ID())
	if err != nil {
		return nil, fmt.Errorf("payment processing failed: %w", err)
	}

	if !paymentResult.Success {
		return nil, fmt.Errorf("payment failed: %s", paymentResult.ErrorMessage)
	}

	// Mark order as paid
	if err := order.MarkAsPaid(); err != nil {
		return nil, fmt.Errorf("failed to mark order as paid: %w", err)
	}

	// Save through port
	if err := uc.orderRepository.Save(order); err != nil {
		return nil, fmt.Errorf("failed to save order: %w", err)
	}

	return order, nil
}
