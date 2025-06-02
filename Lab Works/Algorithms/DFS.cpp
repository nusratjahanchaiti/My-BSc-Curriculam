
 //DFS TRAVERSAL


            //         0
            //       /  \
            //      1--- 4
            //    /  \   |
            //   2----3--|

#include <iostream>
#include <vector>
using namespace std;

// Depth-First Search function
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)  // current node being visited, reference to the adjacency list representing the graph, reference to the vector visited
{

    visited[node] = true;   // Mark the current node as visited
    cout << node << " ";   // Print the node as part of the DFS traversal


    for (int neighbor : adj[node])           // Visit all unvisited neighbors
        {
        if (!visited[neighbor])             // Checks if each neighbor has not been visited yet.
        {
            dfs(neighbor, adj, visited);   // If the neighbor hasn’t been visited call the DFS function.
        }
    }
}

int main() {

    int V = 5;         // Number of vertices

         // Initialize the adjacency list for each vertex
    vector<vector<int>> adj = {
        {1, 4},        // Node 0 is connected to nodes 1 and 4
        {0, 2, 3, 4},  // Node 1 is connected to nodes 0, 2, 3, and 4
        {1, 3},        // Node 2 is connected to nodes 1 and 3
        {1, 2, 4},     // Node 3 is connected to nodes 1, 2, and 4
        {0, 1, 3}      // Node 4 is connected to nodes 0, 1, and 3
    };


    vector<bool> visited(V, false);      // creates a boolean vector with V elements, all initialized to false.  [ 0,0,0,0,0]


    cout << "DFS Traversal: ";          // Perform DFS traversal starting from each unvisited node

    for (int i = 0; i < V; i++)         // Loops over each node from 0 to V-1
    {
        if (!visited[i])               // Checks if the current node i has been visited. If it hasn’t, dfs(i, adj, visited); is called to start a DFS from that node.
            dfs(i, adj, visited);
        }

    cout << endl;

    return 0;
}
