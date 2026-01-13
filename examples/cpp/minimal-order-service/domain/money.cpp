#include "domain/money.hpp"
#include <algorithm>
#include <cctype>

namespace domain {

Money::Money(int64_t amount, const std::string& currency)
    : amount_(amount), currency_(currency) {
    if (amount < 0) {
        throw std::invalid_argument("Amount cannot be negative");
    }
    if (currency.empty() || std::all_of(currency.begin(), currency.end(), ::isspace)) {
        throw std::invalid_argument("Currency cannot be empty");
    }
    
    // Normalize currency to uppercase
    currency_.clear();
    for (char c : currency) {
        if (!std::isspace(c)) {
            currency_ += static_cast<char>(std::toupper(c));
        }
    }
}

Money Money::add(const Money& other) const {
    if (currency_ != other.currency_) {
        throw std::invalid_argument("Cannot add different currencies");
    }
    return Money(amount_ + other.amount_, currency_);
}

} // namespace domain
