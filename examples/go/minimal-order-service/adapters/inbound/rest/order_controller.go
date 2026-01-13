package rest

import (
	"github.com/example/order-service/application/ports/inbound"
	"github.com/example/order-service/domain"
)

// OrderController is an inbound adapter for REST API.
type OrderController struct {
	placeOrderPort inbound.PlaceOrderPort
}

// NewOrderController creates a new OrderController.
func NewOrderController(placeOrderPort inbound.PlaceOrderPort) *OrderController {
	return &OrderController{
		placeOrderPort: placeOrderPort,
	}
}

// PlaceOrderRequest represents the request DTO.
type PlaceOrderRequest struct {
	Amount   int64  `json:"amount"`
	Currency string `json:"currency"`
}

// PlaceOrderResponse represents the response DTO.
type PlaceOrderResponse struct {
	ID       string `json:"id"`
	Amount   int64  `json:"amount"`
	Currency string `json:"currency"`
	Status   string `json:"status"`
}

// PlaceOrder handles a place order request.
func (c *OrderController) PlaceOrder(req PlaceOrderRequest) (*PlaceOrderResponse, error) {
	command := inbound.PlaceOrderCommand{
		Amount:   req.Amount,
		Currency: req.Currency,
	}

	order, err := c.placeOrderPort.PlaceOrder(command)
	if err != nil {
		return nil, err
	}

	return &PlaceOrderResponse{
		ID:       order.ID(),
		Amount:   order.Total().Amount(),
		Currency: order.Total().Currency(),
		Status:   string(order.Status()),
	}, nil
}
