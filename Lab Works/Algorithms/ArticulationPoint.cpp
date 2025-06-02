//ARTICULATION POINT//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform DFS and find articulation points
void dfsArticulation(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& isArticulation, int& time) {
    visited[u] = true;            // Mark the current node as visited
    disc[u] = low[u] = ++time;    // Set discovery time and low value for node 'u'
    int children = 0;              // Count the number of children of node 'u' in DFS tree

    // Traverse all the adjacent nodes of 'u'
    for (int v : adj[u]) {         // For each adjacent vertex 'v' of 'u'
        if (!visited[v]) {         // If 'v' has not been visited
            children++;            // Increment the children count
            parent[v] = u;         // Set 'u' as the parent of 'v'
            dfsArticulation(v, adj, visited, disc, low, parent, isArticulation, time); // Recursively call DFS for 'v'

            // After DFS call for 'v', update the low value of 'u' based on low[v]
            low[u] = min(low[u], low[v]);

            // Case 1: If 'u' is a root and has more than one child
            if (parent[u] == -1 && children > 1) {
                isArticulation[u] = true;  // Mark 'u' as an articulation point
            }

            // Case 2: If 'u' is not a root, and the low value of 'v' is >= discovery time of 'u'
            if (parent[u] != -1 && low[v] >= disc[u]) {
                isArticulation[u] = true;  // Mark 'u' as an articulation point
            }
        }
        // If 'v' is already visited and not the parent of 'u', update low[u] to the minimum of low[u] and disc[v]
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);  // Update low value of 'u' for back edge
        }
    }
}

int main() {
    int V = 5; // Number of vertices in the graph

    // Initialize adjacency list representing the graph
    vector<vector<int>> adj = {
        {1, 4},        // Node 0 is connected to nodes 1 and 4
        {0, 2, 3, 4},  // Node 1 is connected to nodes 0, 2, 3, and 4
        {1, 3},        // Node 2 is connected to nodes 1 and 3
        {1, 2, 4},     // Node 3 is connected to nodes 1, 2, and 4
        {0, 1, 3}      // Node 4 is connected to nodes 0, 1, and 3
    };

    // Initialize variables
    vector<bool> visited(V, false);       // To track whether a node has been visited
    vector<int> disc(V, -1);              // Discovery times of visited nodes
    vector<int> low(V, -1);               // Earliest discovered vertex reachable from each node
    vector<int> parent(V, -1);            // Parent nodes in DFS tree
    vector<bool> isArticulation(V, false); // Boolean vector to mark articulation points
    int time = 0;                         // Counter to keep track of discovery time during DFS

    // Perform DFS for each connected component to find articulation points
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {  // If node 'i' is not visited, start DFS from 'i'
            dfsArticulation(i, adj, visited, disc, low, parent, isArticulation, time); // Call DFS on unvisited node 'i'
        }
    }

    // Print articulation points
    cout << "Articulation Points: ";
    bool hasArticulation = false;
    for (int i = 0; i < V; i++) {
        if (isArticulation[i]) { // If node 'i' is an articulation point
            cout << i << " ";    // Print 'i' as an articulation point
            hasArticulation = true;
        }
    }
    if (!hasArticulation) {   // If no articulation points are found
        cout << "None";        // Print "None"
    }
    cout << endl;

    return 0;  // Return 0 to indicate successful execution of the program
}
