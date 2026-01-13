package domain_test

import (
	"testing"
	"github.com/example/order-service/domain"
)

func TestMoney_NewMoney(t *testing.T) {
	money, err := domain.NewMoney(10000, "USD")
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}
	if money.Amount() != 10000 {
		t.Errorf("Expected amount 10000, got %d", money.Amount())
	}
	if money.Currency() != "USD" {
		t.Errorf("Expected currency USD, got %s", money.Currency())
	}
}

func TestMoney_NegativeAmount(t *testing.T) {
	_, err := domain.NewMoney(-100, "USD")
	if err == nil {
		t.Error("Expected error for negative amount")
	}
}

func TestMoney_EmptyCurrency(t *testing.T) {
	_, err := domain.NewMoney(100, "")
	if err == nil {
		t.Error("Expected error for empty currency")
	}
}

func TestMoney_Add(t *testing.T) {
	money1, _ := domain.NewMoney(10000, "USD")
	money2, _ := domain.NewMoney(5000, "USD")
	
	result, err := money1.Add(money2)
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}
	if result.Amount() != 15000 {
		t.Errorf("Expected amount 15000, got %d", result.Amount())
	}
}

func TestMoney_AddDifferentCurrencies(t *testing.T) {
	money1, _ := domain.NewMoney(10000, "USD")
	money2, _ := domain.NewMoney(5000, "EUR")
	
	_, err := money1.Add(money2)
	if err == nil {
		t.Error("Expected error when adding different currencies")
	}
}

func TestOrder_CreateOrder(t *testing.T) {
	total, _ := domain.NewMoney(10000, "USD")
	order, err := domain.CreateOrder(total)
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}
	if order.ID() == "" {
		t.Error("Expected non-empty order ID")
	}
	if order.Status() != domain.OrderStatusPending {
		t.Errorf("Expected status PENDING, got %s", order.Status())
	}
}

func TestOrder_MarkAsPaid(t *testing.T) {
	total, _ := domain.NewMoney(10000, "USD")
	order, _ := domain.CreateOrder(total)
	
	err := order.MarkAsPaid()
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}
	if order.Status() != domain.OrderStatusPaid {
		t.Errorf("Expected status PAID, got %s", order.Status())
	}
}

func TestOrder_MarkAsPaidTwice(t *testing.T) {
	total, _ := domain.NewMoney(10000, "USD")
	order, _ := domain.CreateOrder(total)
	order.MarkAsPaid()
	
	err := order.MarkAsPaid()
	if err == nil {
		t.Error("Expected error when marking non-pending order as paid")
	}
}
