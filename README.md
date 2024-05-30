# Graph Operations Library

## Overview

This project implements a comprehensive library for performing various operations on graphs. The primary data structure is a graph represented by its adjacency matrix. The library includes functionalities for adding, subtracting, and comparing graphs, as well as incrementing, decrementing, and multiplying graphs by scalars or other graphs. 

## Features

- **Graph Addition and Subtraction**
  - `operator+` and `operator-` to add or subtract two graphs and return a new graph.
  - `operator+=` and `operator-=` to add or subtract another graph to the current graph.

- **Graph Comparison**
  - `operator==` and `operator!=` to check if two graphs are equal or not.
  - `operator>` and `operator<` to check if one graph is a subgraph of another graph.
  - `operator>=` and `operator<=` to check if one graph is greater than or equal to or less than or equal to another graph.

- **Unary Operations**
  - `operator+` to return the graph itself.
  - `operator-` to negate all the values in the adjacency matrix.

- **Prefix and Postfix Increment/Decrement**
  - `operator++` and `operator--` for prefix increment/decrement.
  - `operator++(int)` and `operator--(int)` for postfix increment/decrement.

- **Multiplication**
  - `operator*` and `operator*=` to multiply a graph by a scalar or another graph.

- **Output**
  - `operator<<` to print the adjacency matrix of the graph.

## Getting Started

### Prerequisites

- C++ compiler supporting C++11 or later.

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/graph-operations-library.git
   ```
2. Navigate to the project directory:
   ```sh
   cd graph-operations-library
   ```

### Usage

#### Example

```cpp
#include <iostream>
#include "Graph.h"

int main() {
    // Create two graphs
    ariel::Graph g1;
    ariel::Graph g2;

    // Load graphs with adjacency matrices
    g1.loadGraph({{0, 1}, {1, 0}});
    g2.loadGraph({{1, 0}, {0, 1}});

    // Add graphs
    ariel::Graph g3 = g1 + g2;
    std::cout << "Sum of g1 and g2:\n" << g3;

    // Subtract graphs
    ariel::Graph g4 = g1 - g2;
    std::cout << "Difference of g1 and g2:\n" << g4;

    // Multiply graph by scalar
    ariel::Graph g5 = g1 * 2;
    std::cout << "g1 multiplied by 2:\n" << g5;

    // Check equality
    if (g1 == g2) {
        std::cout << "g1 and g2 are equal\n";
    } else {
        std::cout << "g1 and g2 are not equal\n";
    }

    return 0;
}
```

## Documentation

### Graph Class

#### Methods

- `Graph operator+(Graph& other)`: Adds two graphs.
- `Graph operator+=(Graph& other)`: Adds a graph to the current graph.
- `Graph operator-(Graph& other)`: Subtracts one graph from another.
- `Graph operator-=(Graph& other)`: Subtracts a graph from the current graph.
- `Graph operator*(int scalar)`: Multiplies a graph by a scalar.
- `Graph operator*=(int scalar)`: Multiplies the current graph by a scalar.
- `Graph operator*(Graph& other)`: Multiplies two graphs.
- `Graph operator*=(Graph& other)`: Multiplies the current graph by another graph.
- `bool operator==(Graph& other)`: Checks if two graphs are equal.
- `bool operator!=(Graph& other)`: Checks if two graphs are not equal.
- `bool operator>(Graph& other)`: Checks if the current graph contains the other graph as a subgraph.
- `bool operator<(Graph& other)`: Checks if the other graph contains the current graph as a subgraph.
- `bool operator>=(Graph& other)`: Checks if the current graph is greater than or equal to the other graph.
- `bool operator<=(Graph& other)`: Checks if the current graph is less than or equal to the other graph.
- `Graph operator++()`: Prefix increment operator.
- `Graph operator++(int)`: Postfix increment operator.
- `Graph operator--()`: Prefix decrement operator.
- `Graph operator--(int)`: Postfix decrement operator.
- `Graph operator+()`: Unary plus operator.
- `Graph operator-()`: Unary minus operator.
- `friend ostream& operator<<(ostream& os, const Graph& graph)`: Output operator to print the adjacency matrix.
