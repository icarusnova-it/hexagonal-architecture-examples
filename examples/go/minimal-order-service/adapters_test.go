package outbound_test

import (
	"testing"
	"github.com/example/order-service/adapters/outbound"
	"github.com/example/order-service/domain"
)

func TestInMemoryOrderRepository_SaveAndFind(t *testing.T) {
	repository := outbound.NewInMemoryOrderRepository()
	total, _ := domain.NewMoney(10000, "USD")
	order, _ := domain.NewOrder("order-1", total)

	err := repository.Save(order)
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}

	retrieved, err := repository.FindByID("order-1")
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}
	if retrieved == nil {
		t.Fatal("Expected non-nil order")
	}
	if retrieved.ID() != order.ID() {
		t.Errorf("Expected order ID %s, got %s", order.ID(), retrieved.ID())
	}
}

func TestInMemoryOrderRepository_FindNonExistent(t *testing.T) {
	repository := outbound.NewInMemoryOrderRepository()
	
	retrieved, err := repository.FindByID("non-existent")
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}
	if retrieved != nil {
		t.Error("Expected nil for non-existent order")
	}
}

func TestFakePaymentGateway_ProcessPayment(t *testing.T) {
	gateway := outbound.NewFakePaymentGateway()
	amount, _ := domain.NewMoney(10000, "USD")

	result, err := gateway.ProcessPayment(amount, "order-1")
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}
	if !result.Success {
		t.Error("Expected payment to succeed")
	}
	if result.TransactionID == "" {
		t.Error("Expected non-empty transaction ID")
	}
}
