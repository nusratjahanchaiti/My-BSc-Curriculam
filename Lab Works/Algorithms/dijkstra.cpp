#include <iostream>
#include <climits>

using namespace std;

#define NUM_VERTICES 6 // Number of vertices in the graph (A, B, C, D, E, F)

// Function to find the vertex with the minimum distance value
int findMinDistanceVertex(int distances[], bool visited[]) {
    int minDistance = INT_MAX, minIndex;

    for (int vertex = 0; vertex < NUM_VERTICES; vertex++) {
        if (!visited[vertex] && distances[vertex] <= minDistance) {
            minDistance = distances[vertex];
            minIndex = vertex;
        }
    }

    return minIndex;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int adjacencyMatrix[NUM_VERTICES][NUM_VERTICES], int sourceVertex) {
    int distances[NUM_VERTICES]; // Array to store the shortest distances from source to each vertex
    bool visited[NUM_VERTICES]; // Array to track if a vertex has been visited

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < NUM_VERTICES; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance from the source to itself is always 0
    distances[sourceVertex] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < NUM_VERTICES - 1; count++) {
        // Get the vertex with the minimum distance from the set of vertices not yet visited
        int currentVertex = findMinDistanceVertex(distances, visited);

        // Mark the picked vertex as visited
        visited[currentVertex] = true;

        // Update distances[] for the adjacent vertices of the picked vertex
        for (int adjacentVertex = 0; adjacentVertex < NUM_VERTICES; adjacentVertex++) {
            // Check if there is an edge between currentVertex and adjacentVertex
            // and if we have found a shorter path to adjacentVertex
            if (!visited[adjacentVertex] && adjacencyMatrix[currentVertex][adjacentVertex] != 0 && distances[currentVertex] != INT_MAX) {
                int edgeCost = adjacencyMatrix[currentVertex][adjacentVertex]; // c(u, v) - the cost of the edge
                int newDistance = distances[currentVertex] + edgeCost; // d(u) + c(u, v)

                // Apply the rule: if d(u) + c(u, v) < d(v), update d(v)
                if (newDistance < distances[adjacentVertex]) {
                    distances[adjacentVertex] = newDistance;
                }
            }
        }
    }

    // Print the constructed distance array
    cout << "Vertex\tDistance from Source (" << sourceVertex << ")\n";
    for (int i = 0; i < NUM_VERTICES; i++) {
        cout << i << "\t";
        if (distances[i] == INT_MAX)
            cout << "INF"; // INF means unreachable
        else
            cout << distances[i];
        cout << endl;
    }
}

int main() {
    // Create a graph using an adjacency matrix based on the provided costs
    int adjacencyMatrix[NUM_VERTICES][NUM_VERTICES] = {
        {0, 14, 9, 0, 0, 7},    // A -> B (14), A -> C (9), A -> F (7)
        {14, 0, 2, 8, 0, 0},     // B -> A (14), B -> C (2), B -> D (8)
        {9, 2, 0, 0, 11, 10},    // C -> A (9), C -> B (2), C -> E (11), C -> F (10)
        {0, 8, 0, 0, 6, 0},      // D -> B (8), D -> E (6)
        {0, 0, 11, 6, 0, 15},    // E -> C (11), E -> D (6), E -> F (15)
        {7, 0, 10, 0, 15, 0}     // F -> A (7), F -> C (10), F -> E (15)
    };

    int sourceVertex = 0; // Set source vertex as A (which is vertex 0)
    dijkstra(adjacencyMatrix, sourceVertex);

    return 0;
}
