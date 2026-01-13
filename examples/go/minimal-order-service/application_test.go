package usecases_test

import (
	"testing"
	"github.com/example/order-service/application/ports/inbound"
	"github.com/example/order-service/application/usecases"
	"github.com/example/order-service/adapters/outbound"
	"github.com/example/order-service/domain"
)

func TestPlaceOrderUseCase_PlaceOrder(t *testing.T) {
	// Arrange
	repository := outbound.NewInMemoryOrderRepository()
	paymentGateway := outbound.NewFakePaymentGateway()
	useCase := usecases.NewPlaceOrderUseCase(repository, paymentGateway)

	// Act
	command := inbound.PlaceOrderCommand{
		Amount:   10000,
		Currency: "USD",
	}
	order, err := useCase.PlaceOrder(command)

	// Assert
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}
	if order == nil {
		t.Fatal("Expected non-nil order")
	}
	if order.Status() != domain.OrderStatusPaid {
		t.Errorf("Expected status PAID, got %s", order.Status())
	}

	// Verify order was saved
	savedOrder, err := repository.FindByID(order.ID())
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}
	if savedOrder == nil {
		t.Fatal("Expected order to be saved")
	}
	if savedOrder.ID() != order.ID() {
		t.Errorf("Expected order ID %s, got %s", order.ID(), savedOrder.ID())
	}
}
