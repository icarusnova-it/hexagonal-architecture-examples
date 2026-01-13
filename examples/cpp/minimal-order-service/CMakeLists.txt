cmake_minimum_required(VERSION 3.15)
project(OrderService)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(DOMAIN_SOURCES
    domain/money.cpp
    domain/order.cpp
)

set(APPLICATION_SOURCES
    application/usecases/place_order_use_case.cpp
)

set(ADAPTERS_SOURCES
    adapters/outbound/in_memory_repository.cpp
    adapters/outbound/fake_payment_gateway.cpp
)

set(TEST_SOURCES
    tests/test_domain.cpp
    tests/test_usecases.cpp
    tests/test_adapters.cpp
)

# Main executable
add_executable(order_service
    main.cpp
    ${DOMAIN_SOURCES}
    ${APPLICATION_SOURCES}
    ${ADAPTERS_SOURCES}
)

# Test executable
add_executable(test_order_service
    ${TEST_SOURCES}
    ${DOMAIN_SOURCES}
    ${APPLICATION_SOURCES}
    ${ADAPTERS_SOURCES}
)

# Include directories
target_include_directories(order_service PRIVATE .)
target_include_directories(test_order_service PRIVATE .)
