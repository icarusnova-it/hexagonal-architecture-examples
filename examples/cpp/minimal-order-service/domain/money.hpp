#ifndef DOMAIN_MONEY_HPP
#define DOMAIN_MONEY_HPP

#include <string>
#include <stdexcept>

namespace domain {

/**
 * Value object representing money.
 * Immutable and validated.
 */
class Money {
public:
    /**
     * Creates a Money value object.
     * @param amount Amount in cents (must be non-negative)
     * @param currency Currency code (must not be empty)
     * @throws std::invalid_argument If amount is negative or currency is empty
     */
    Money(int64_t amount, const std::string& currency);
    
    int64_t amount() const { return amount_; }
    const std::string& currency() const { return currency_; }
    
    /**
     * Adds two Money values with the same currency.
     * @param other Another Money value to add
     * @return New Money value with the sum
     * @throws std::invalid_argument If currencies don't match
     */
    Money add(const Money& other) const;
    
    bool operator==(const Money& other) const {
        return amount_ == other.amount_ && currency_ == other.currency_;
    }

private:
    int64_t amount_;
    std::string currency_;
};

} // namespace domain

#endif // DOMAIN_MONEY_HPP
