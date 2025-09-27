# Containers

A custom implementation of C++ STL-like containers library.


## Description
This project implements four container classes: `list`, `array`, `stack`, and `vector`. All containers are template-based, support iterators, and follow STL semantics.


## Containers Implemented

| Container | Description | Key Features |
|-----------|-------------|--------------|
| **`s21::array`** | Fixed-size array | Stack-allocated, constant size |
| **`s21::list`** | Doubly-linked list | Bidirectional iterators, O(1) insert/erase |
| **`s21::stack`** | LIFO container | Last-in-first-out operations |
| **`s21::vector`** | Dynamic array | Random access, automatic resizing |


## Requirements

- C++20 compatible compiler
- Google Test (for testing)


## Installation
- Clone the repository on your computer.
- Navigate to the `src/` directory.
- Build the project: `make` or `make all`.


## Testing
- To run unit tests:`make test`
- To generate a test coverage report: `make gcov_report`
