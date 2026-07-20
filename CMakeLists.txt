cmake_minimum_required(VERSION 3.14)
project(BankSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(bank-system
    src/main.cpp
    src/BankAccount.cpp
    src/Bank.cpp
)
