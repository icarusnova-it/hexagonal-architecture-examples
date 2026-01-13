package domain

import (
	"errors"
	"strings"
)

// Money represents a monetary value.
// It's a value object - immutable and validated.
type Money struct {
	amount   int64  // in cents
	currency string
}

// NewMoney creates a new Money value object.
func NewMoney(amount int64, currency string) (*Money, error) {
	if amount < 0 {
		return nil, errors.New("amount cannot be negative")
	}
	if strings.TrimSpace(currency) == "" {
		return nil, errors.New("currency cannot be empty")
	}
	return &Money{
		amount:   amount,
		currency: strings.ToUpper(strings.TrimSpace(currency)),
	}, nil
}

// Amount returns the amount in cents.
func (m *Money) Amount() int64 {
	return m.amount
}

// Currency returns the currency code.
func (m *Money) Currency() string {
	return m.currency
}

// Add adds two Money values with the same currency.
func (m *Money) Add(other *Money) (*Money, error) {
	if m.currency != other.currency {
		return nil, errors.New("cannot add different currencies")
	}
	return NewMoney(m.amount+other.amount, m.currency)
}

// Equals checks if two Money values are equal.
func (m *Money) Equals(other *Money) bool {
	if other == nil {
		return false
	}
	return m.amount == other.amount && m.currency == other.currency
}
