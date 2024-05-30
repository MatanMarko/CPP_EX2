//322318080
//matanmarkovits@gmail.com

#pragma once

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;
using std::vector;

namespace ariel {
    class Graph {

    private:
        vector<vector<int>> adjacencyMatrix; // The adjacency matrix of the graph.
        size_t numVertices;    // The number of vertices in the graph.

    public:
        //Graph(); // Constructor.
    
        void loadGraph(const vector<vector<int>> &graph);

        string printGraph();

        bool isDirectedGraph();

        bool isWeightedGraph();

        bool isPositiveWeightedGraph();

        vector<vector<int>> getAdjacencyMatrix();
        vector<vector<int>> getAdjacencyMatrix() const;
       
        unsigned int getNumVertices();
        unsigned int getNumVertices() const;

        vector<size_t> getNeighbors(size_t vertex);

        Graph reverse();


        //Arithmetic operators:

        Graph operator+(Graph& Lgraph);  // graph1 + graph2

        Graph operator+=(Graph& other); // graph1 += graph2

        Graph operator+();  // unary plus operator (no effect)


        Graph operator-(Graph& other);  // graph1 - graph2

        Graph operator-=(Graph& other); // graph1 -= graph2

        Graph operator-();  // unary minus operator


        //Comparison operators:

        bool operator==(Graph& other);  // graph1 == graph2

        bool operator!=(Graph& other);  // graph1 != graph2

        bool operator>(Graph& other);   // graph1 < graph2

        bool operator<(Graph& other);  // graph1 <= graph2

        bool operator>=(Graph& other);   // graph1 > graph2

        bool operator<=(Graph& other);  // graph1 >= graph2

        //Prefix increment and decrement operators:

        Graph operator++();  // ++graph

        Graph operator++(int);  // graph++

        Graph operator--();  // --graph

        Graph operator--(int);  // graph--


        //Multiplication operators:

        Graph operator*(int scalar);  // graph * scalar

        Graph operator*=(int scalar);  // graph *= scalar

        Graph operator*(Graph& other);  // graph1 * graph2

        Graph operator*=(Graph& other);  // graph1 *= graph2

        //Output operator:

        friend ostream& operator<<(ostream& os, const Graph& graph);  // cout << graph


    };
} // namespace ariel

#endif // GRAPH_HPP
