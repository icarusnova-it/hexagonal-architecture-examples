package com.example.order.domain;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class MoneyTest {
    @Test
    void shouldCreateMoneyWithValidAmountAndCurrency() {
        Money money = new Money(10000, "USD");
        assertEquals(10000, money.getAmount());
        assertEquals("USD", money.getCurrency());
    }

    @Test
    void shouldThrowExceptionForNegativeAmount() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Money(-100, "USD");
        });
    }

    @Test
    void shouldThrowExceptionForNullCurrency() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Money(100, null);
        });
    }

    @Test
    void shouldNormalizeCurrencyToUpperCase() {
        Money money = new Money(100, "usd");
        assertEquals("USD", money.getCurrency());
    }

    @Test
    void shouldAddMoneyWithSameCurrency() {
        Money money1 = new Money(10000, "USD");
        Money money2 = new Money(5000, "USD");
        Money result = money1.add(money2);
        assertEquals(15000, result.getAmount());
        assertEquals("USD", result.getCurrency());
    }

    @Test
    void shouldThrowExceptionWhenAddingDifferentCurrencies() {
        Money money1 = new Money(10000, "USD");
        Money money2 = new Money(5000, "EUR");
        assertThrows(IllegalArgumentException.class, () -> {
            money1.add(money2);
        });
    }

    @Test
    void shouldBeEqualWhenAmountAndCurrencyMatch() {
        Money money1 = new Money(10000, "USD");
        Money money2 = new Money(10000, "USD");
        assertEquals(money1, money2);
    }
}
