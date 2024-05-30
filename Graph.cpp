//322318080
//matanmarkovits@gmail.com

#include "Graph.hpp"

using namespace std;
using std::vector;

namespace ariel {


// private:
//     vector<vector<int>> adjacencyMatrix; // The adjacency matrix of the graph.
//     int numVertices;    // The number of vertices in the graph.

//public:
    /*
    Gets a matrix of neighbors, checks if the input matrix is valid and loads it into the graph.
    */
    void Graph::loadGraph(const vector<vector<int>> &graph) {
        if (graph.size() == 0) {
            throw invalid_argument("The input matrix is empty.");
        }

        for (unsigned int i = 0; i < graph.size(); i++) {
            if (graph[i].size() != graph.size()) {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
            for (unsigned int j = 0; j < graph[i].size(); j++) {
                if (i == j && graph[i][j] != 0) {
                    throw invalid_argument("The diagonal of the matrix must be zero.");
                }
            }
        }

        adjacencyMatrix = graph;
        numVertices = graph.size();
    }

    /*
    Prints the graph.
    */

    // string Graph::printGraph() {
    //     string str = "";
    //     for (const auto& row : adjacencyMatrix) {
    //         for (const auto& value : row) {
    //             str += to_string(value) + " ";
    //         }
    //         str += "\n";
    //     }
    //     return str;
    // }

    string Graph::printGraph() {
    string str = "";
    for (const auto& row : adjacencyMatrix) {
        str += "[";
        for (const auto& value : row) {
            str += to_string(value) + ", ";
        }
        str = str.substr(0, str.size()-2); // Remove the last comma and space
        str += "], ";
    }
    str = str.substr(0, str.size()-2); // Remove the last comma and space
    return str;
}

    /*
    Inputed graph:
        - Directed graph
            - unweighted graph
            - weighted graph
                - positive weights
                - includes negative weights
                    - negative cycle (in Algotiyhms.cpp)
                    - no negative cycle (in Algotiyhms.cpp)
        
        - Undirected graph
            - unweighted graph
            - weighted graph
                - positive weights
                - includes negative weights
    */


   /*
    Check if the graph is directed.
    If the input matrix is symmetric, the graph is undirected.
   */
    bool Graph::isDirectedGraph() {
        for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                    return true;
                }
            }
        }
        return false;
    }

    /*
    Check if the graph is weighted.
    */
    bool Graph::isWeightedGraph() {
        for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                if (adjacencyMatrix[i][j] != 0 && adjacencyMatrix[i][j] != 1) {
                    return true;
                }
            }
        }
        return false;
    }

    /*
    Check if the graph is positive weighted.
    */
    bool Graph::isPositiveWeightedGraph() {
        for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                if (adjacencyMatrix[i][j] < 0) {
                    return false;
                }
            }
        }
        return true;
    }
    
    /*
    get the adjacency matrix of the graph.
    */
    vector<vector<int>> Graph::getAdjacencyMatrix() {
        return adjacencyMatrix;
    }

    vector<vector<int>> Graph::getAdjacencyMatrix() const{
        return adjacencyMatrix;
    }

    /*
    Get the number of vertices in the graph.
    */
    unsigned int Graph::getNumVertices() {
        return numVertices;
    }

    unsigned int Graph::getNumVertices() const{
        return numVertices;
    }

    /*
    Get the neighbors of a given vertex.
    @param vertex The vertex to get its neighbors.
    @return A vector of the neighbors of the given vertex.
    */
    vector<size_t> Graph::getNeighbors(size_t vertex) {
        vector<size_t> neighbors;
        for (size_t i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[vertex][i] != 0) {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }

    Graph Graph::reverse() {
        Graph reversedGraph;
        vector<vector<int>> reversedMatrix(static_cast<size_t>(numVertices), vector<int>(static_cast<size_t>(numVertices), 0));

        for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                reversedMatrix[i][j] = adjacencyMatrix[j][i];
            }
        }
        reversedGraph.loadGraph(reversedMatrix);
        return reversedGraph;
    }

    ////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////   EX2 additions   ////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////Arithmetic operators: /////////////////////////////////

    /*
    Add two graphs.
    @param other The graph to add to the current graph.
    @return The sum of the two graphs as a new graph.
    */
    Graph Graph::operator+(Graph& other) {

        unsigned int size = getNumVertices();

        if (size != other.getNumVertices()) {
            throw invalid_argument("The graphs must have the same number of vertices.");
        }

        vector<vector<int>> newMatrix(size, vector<int>((size), 0));
        for (unsigned int i = 0; i < size; i++) {
            for (unsigned int j = 0; j < size; j++) {
                if (i != j){
                    newMatrix[i][j] = adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j];
                }
                else{
                    newMatrix[i][j] = 0;
                }
            }
        }

        Graph newGraph;
        newGraph.loadGraph(newMatrix);
        return newGraph;
    }

    /*
    Add a graph to the current graph.
    @param other The graph to add to the current graph.
    @return The sum of the two graphs as a new graph.
    */
    Graph Graph::operator+=(Graph& other) {
        if (numVertices != other.numVertices) {
            throw invalid_argument("The graphs must have the same number of vertices.");
        }

        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    /*
    Unary plus operator.
    */
    Graph Graph::operator+() {
        return *this;
    }

    /*
    Subtract two graphs.
    @param other The graph to subtract from the current graph.
    @return The difference of the two graphs as a new graph.
    */
    Graph Graph::operator-(Graph& other) {
        if (numVertices != other.numVertices) {
            throw invalid_argument("The graphs must have the same number of vertices.");
        }

        vector<vector<int>> newMatrix((numVertices, vector<int>(numVertices), 0));
        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                newMatrix[i][j] = adjacencyMatrix[i][j] - other.adjacencyMatrix[i][j];
            }
        }

        Graph newGraph;
        newGraph.loadGraph(newMatrix);
        return newGraph;
    }

    /*
    Subtract a graph from the current graph.
    @param other The graph to subtract from the current graph.
    @return The difference of the two graphs as a new graph.
    */
    Graph Graph::operator-=(Graph& other) {
        if (numVertices != other.numVertices) {
            throw invalid_argument("The graphs must have the same number of vertices.");
        }

        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    /*
    Unary minus operator.
    */
    Graph Graph::operator-() {
        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                adjacencyMatrix[i][j] = -adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    /////////////////////////////////Comparison operators:////////////////////////////////

    /*
    Check if two graphs are equal.
    @param other The graph to compare with the current graph.
    @return True if the two graphs are equal, false otherwise.
    */
    bool Graph::operator==(Graph& other) {
        if (numVertices != other.numVertices) {
            return false;
        }

        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                if (adjacencyMatrix[i][j] != other.adjacencyMatrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    /*
    Check if two graphs are not equal.
    @param other The graph to compare with the current graph.
    @return True if the two graphs are not equal, false otherwise.
    */

    bool Graph::operator!=(Graph& other) {
        return !(*this == other);
    }

    /*
    Check if the current graph is greater than the other graph- meaning that the cuurent graph's adjacency matrix contains the other graph's adjacency matrix.
    @param other The graph to compare with the current graph.
    @return True if the current graph is greater than the other graph, false otherwise.
    for example:    
                    0  0  0  0  1  1  1
                    0  0  0  1  0  1  1
                    0  0  0  1  1  0  1                                 0  1  1  1
                    0  0  0  0  1  1  0    --> contains the graph -->   1  0  1  1
                    0  0  0  0  0  0  0                                 1  1  0  1
                    0  0  0  0  0  0  0                                 0  1  1  0
                    0  0  0  0  0  0  0
    */
    bool Graph::operator>(Graph& other) {
        if (!(numVertices > other.numVertices)) {
            return false;
        }

        for (unsigned int i = 0; i < numVertices-other.numVertices+1; i++){     //moving until the last possible row which the smaller graph can be in
            for (unsigned int j = 0; j < numVertices-other.numVertices+1; j++){     //moving until the last possible column which the smaller graph can be in
                bool flag = true;       //flag to check if the smaller graph is in the current graph
                for (unsigned int k = 0; k < other.numVertices; k++){
                    for (unsigned int l = 0; l < other.numVertices; l++){
                        if (adjacencyMatrix[i+k][j+l] != other.adjacencyMatrix[k][l]){      //if the part of the graph is not equal to the other graph
                            flag = false;
                            break;
                        }
                    }
                    if (!flag){
                        break;
                    }
                }
                if (flag){
                    return true;
                }
            }
        }
        
        return false;
    }

    /*
    Check if the current graph is less than the other graph.
    @param other The graph to compare with the current graph.
    @return True if the current graph is less than the other graph, false otherwise.
    */
    bool Graph::operator<(Graph& other) {
        return other > *this;
    }

    /*
    Check if the current graph is greater than or equal to the other graph.
    @param other The graph to compare with the current graph.
    @return True if the current graph is greater than or equal to the other graph, false otherwise.
    */
    bool Graph::operator>=(Graph& other) {
        if (*this > other || *this == other){
            return true;
        }
        return false;
    }

    /*
    Check if the current graph is less than or equal to the other graph.
    @param other The graph to compare with the current graph.
    @return True if the current graph is less than or equal to the other graph, false otherwise.
    */
    bool Graph::operator<=(Graph& other) {
        if (*this < other || *this == other){
            return true;
        }
        return false;
    }


    /////////////////// Prefix increment and decrement operators: ///////////////////////////

    /*
    Prefix increment operator. Increments all the values in the adjacency matrix by 1.
    (++graph)
    the function increments the graph and then returns the graph.
    */
    Graph Graph::operator++() {
        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                adjacencyMatrix[i][j]++;
            }
        }
        return *this;
    }

    /*
    Postfix increment operator. Increments all the values in the adjacency matrix by 1.
    (graph++)
    the function returns the graph before the increment, and then increments the graph.
    */
    Graph Graph::operator++(int) {
        Graph temp = *this;
        ++*this;
        return temp;
    }

    /*
    Prefix decrement operator. Decrements all the values in the adjacency matrix by 1.
    (--graph)
    the function decrements the graph and then returns the graph.
    */
    Graph Graph::operator--() {
        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                adjacencyMatrix[i][j]--;
            }
        }
        return *this;
    }

    /*
    Postfix decrement operator. Decrements all the values in the adjacency matrix by 1.
    (graph--)
    the function returns the graph before the decrement, and then decrements the graph.
    */
    Graph Graph::operator--(int) {
        Graph temp = *this;
        --*this;
        return temp;
    }

    ////////////////////////// Multiplication operators: //////////////////////////////

    /*
    Multiply a graph by a scalar.
    @param scalar The scalar to multiply the graph by.
    @return The product of the graph and the scalar as a new graph.
    */
    Graph Graph::operator*(int scalar) {    // graph * scalar
        vector<vector<int>> newMatrix((numVertices, vector<int>(numVertices), 0));
        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                newMatrix[i][j] = adjacencyMatrix[i][j] * scalar;
            }
        }

        Graph newGraph;
        newGraph.loadGraph(newMatrix);
        return newGraph;
    }

    /*
    Multiply the current graph by a scalar.
    @param scalar The scalar to multiply the graph by.
    @return The product of the graph and the scalar as a new graph.
    */
    Graph Graph::operator*=(int scalar) {   // graph *= scalar
        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                adjacencyMatrix[i][j] *= scalar;
            }
        }
        return *this;
    }


    // Graph Graph::operator*(Graph &g) // Multiply the weights of the two graphs
    // {
    //     if (adjacencyMatrix[0].size() != g.getNumVertices())
    //     {
    //         throw invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    //     }
    //     vector<vector<int>> newGraph;
    //     for (size_t i = 0; i < adjacencyMatrix.size(); i++)
    //     {
    //         vector<int> row;
    //         for (size_t j = 0; j < g.getNumVertices(); j++)
    //         {
    //             int sum = 0;
    //             for (size_t k = 0; k < adjacencyMatrix[i].size(); k++)
    //             {
    //                 sum += adjacencyMatrix[i][k] * g.adjacencyMatrix[k][j];
    //             }
    //             row.push_back(sum);
    //         }
    //         newGraph.push_back(row);
    //     }
    //     for (size_t i = 0; i < newGraph.size(); i++)
    //     {
    //         newGraph[i][i] = 0;
    //     }
    //     Graph newG;
    //     newG.loadGraph(newGraph);
    //     return newG;
    // }


    /*
    Multiply two graphs.
    @param other The graph to multiply with the current graph.
    @return The product of the two graphs as a new graph.
    */
    Graph Graph::operator*(Graph& other) {      // graph1 * graph2
        if (numVertices != other.numVertices) {
            throw invalid_argument("The graphs must have the same number of vertices.");
        }

        vector<vector<int>> newMatrix((numVertices, vector<int>(numVertices), 0));
        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                for (unsigned int k = 0; k < numVertices; k++) {
                    newMatrix[i][j] += adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
                }
            }
        }

        Graph newGraph;
        newGraph.loadGraph(newMatrix);
        return newGraph;
    }

    /*
    Multiply the current graph by another graph.
    @param other The graph to multiply with the current graph.
    @return The product of the two graphs as a new graph.
    */
    Graph Graph::operator*=(Graph& other) {     // graph1 *= graph2
        if (numVertices != other.numVertices) {
            throw invalid_argument("The graphs must have the same number of vertices.");
        }

        vector<vector<int>> newMatrix((numVertices, vector<int>(numVertices), 0));
        for (unsigned int i = 0; i < numVertices; i++) {
            for (unsigned int j = 0; j < numVertices; j++) {
                for (unsigned int k = 0; k < numVertices; k++) {
                    newMatrix[i][j] += adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
                }
            }
        }

        adjacencyMatrix = newMatrix;
        return *this;
    }

    ///////////////////////////// Output operators: /////////////////////////////////

    /*
    Output operator.
    prints the adjacency matrix of the graph.
    */
    ostream& operator<<(ostream& os, const Graph& graph) {
        for (const auto& row : graph.adjacencyMatrix) {
            for (const auto& value : row) {
                os << value << " ";
            }
            os << endl;
        }
        return os;
    }

    



} // namespace ariel

