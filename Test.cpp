//322318080
//matanmarkovits@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test 1")
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    CHECK(g1.printGraph() == "[0, 1, 0], [1, 0, 1], [0, 1, 0]");
}

TEST_CASE("Test 2")
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    CHECK(g1.isDirectedGraph() == false);
}

TEST_CASE("Test 3")
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    CHECK(g1.isWeightedGraph() == false);
}

TEST_CASE("Test 4")
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    CHECK(g1.isPositiveWeightedGraph() == true);
}

TEST_CASE("Test 5")
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    CHECK(g1.getNumVertices() == 3);
}

TEST_CASE("Test 6")
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    CHECK(g1.getAdjacencyMatrix() == graph);
}

TEST_CASE("Test 7")
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    CHECK(g1.getNeighbors(0) == vector<size_t>{1});
}

TEST_CASE("Test 8")
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    CHECK(g1.reverse().printGraph() == "[0, 1, 0], [1, 0, 1], [0, 1, 0]");
}

TEST_CASE("Test 9")
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    ariel::Graph g2;
    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    ariel::Graph g3 = g1 + g2; // Add the two graphs together.
    CHECK(g3.printGraph() == "[0, 2, 1], [2, 0, 3], [1, 3, 0]");
}

TEST_CASE("Test 10")
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    g1 *= -2;        // Multiply the graph by -2.
    CHECK(g1.printGraph() == "[0, -2, 0], [-2, 0, -2], [0, -2, 0]");
}

// TEST_CASE("Test 11")
// {
//     ariel::Graph g1;
//     // 3x3 matrix that represents a connected graph.
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph); // Load the graph to the object.

//     ariel::Graph g2;
//     // 3x3 matrix that represents a weighted connected graph.
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     g2.loadGraph(weightedGraph); // Load the graph to the object.

//     ariel::Graph g4 = g1 * g2; // Multiply the two graphs together.
//     CHECK(g4.printGraph() == "[0, 0, 2], [1, 0, 1], [1, 0, 0]");
// }

TEST_CASE("Test 12")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph); // Load the graph to the object.

    CHECK_THROWS(g1 * g2);
}

TEST_CASE("Test 13")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.

    CHECK(g1 == g2);
}

TEST_CASE("Test 14")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 6, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.

    CHECK(g1 != g2);  
}

TEST_CASE("Test 15")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.

    CHECK(g1 > g2); //expected true
}

TEST_CASE("Test 16")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.

    CHECK(g1 < g2); //expected true
}

TEST_CASE("Test 17")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.

    CHECK(g1 >= g2);
}

TEST_CASE("Test 18")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.

    CHECK(g1 <= g2);
}

TEST_CASE("Test 19")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.
    Graph g3 = g1 + g2;
    Graph g4 = g2 + g1;
    CHECK(g3 == g4);
}

TEST_CASE("Test 20")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.

     ariel::Graph g3;   //= g1
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph30 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g3.loadGraph(graph30); // Load the graph to the object.
    
    g1 -= g2;
    g2 -= g3;

    g1.printGraph();
    g2.printGraph();
    
    CHECK(g1 == g2);
}

TEST_CASE("Test 21")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 2, 0, 0, 2},
        {2, 0, 3, 0, 0},
        {0, 2, 0, 4, 0},
        {0, 0, 2, 0, 5},
        {2, 0, 0, 2, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 2, 0, 0},
        {0, 1, 0, 3, 0},
        {0, 0, 1, 0, 4},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.

    ariel::Graph g3;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g3.loadGraph(graph4); // Load the graph to the object.

    g1 -= g2;
    CHECK(g1 == g3);    //expected true
}

TEST_CASE("Test 22")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 2, 0, 0, 1},
        {1, 0, 3, 0, 0},
        {0, 1, 0, 4, 0},
        {0, 0, 1, 0, 5},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph2); // Load the graph to the object.

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 2, 0, 0},
        {0, 1, 0, 3, 0},
        {0, 0, 1, 0, 4},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.

    ariel::Graph g3;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph4 = {
        {0, 3, 0, 0, 2},
        {2, 0, 5, 0, 0},
        {0, 2, 0, 7, 0},
        {0, 0, 2, 0, 9},
        {2, 0, 0, 2, 0}};
    g3.loadGraph(graph4); // Load the graph to the object.

    g1 += g2;
    CHECK(g1 == g3);    //expected true
}