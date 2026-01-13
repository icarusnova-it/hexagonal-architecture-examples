#ifndef DOMAIN_ORDER_HPP
#define DOMAIN_ORDER_HPP

#include "domain/money.hpp"
#include <string>
#include <memory>

namespace domain {

enum class OrderStatus {
    PENDING,
    PAID
};

/**
 * Domain entity representing an order.
 */
class Order {
public:
    /**
     * Creates an Order with the given ID and total.
     * @param id Unique order identifier
     * @param total Total amount as Money
     * @throws std::invalid_argument If id is empty or total is null
     */
    Order(const std::string& id, std::shared_ptr<Money> total);
    
    /**
     * Creates a new Order with a generated ID.
     * @param total Total amount as Money
     * @return New Order instance
     */
    static std::unique_ptr<Order> create(std::shared_ptr<Money> total);
    
    const std::string& id() const { return id_; }
    std::shared_ptr<Money> total() const { return total_; }
    OrderStatus status() const { return status_; }
    
    /**
     * Marks the order as paid.
     * @throws std::logic_error If order is not in PENDING status
     */
    void markAsPaid();
    
    bool operator==(const Order& other) const {
        return id_ == other.id_;
    }

private:
    std::string id_;
    std::shared_ptr<Money> total_;
    OrderStatus status_;
    
    static std::string generateId();
};

} // namespace domain

#endif // DOMAIN_ORDER_HPP
