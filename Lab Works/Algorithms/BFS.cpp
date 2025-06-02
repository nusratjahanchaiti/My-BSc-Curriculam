 // BFS TRAVERSAL


            //         0
            //       /  \
            //      1--- 4
            //    /  \   |
            //   2----3--|

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(const vector<vector<int>>& adj, int start) {
    int V = adj.size();
    vector<bool> visited(V, false); // Track visited nodes
    queue<int> q; // Queue for BFS

    // Start BFS from the given start node
    visited[start] = true; // Mark start node as visited
    q.push(start); // Enqueue start node

    while (!q.empty()) {
        int node = q.front(); // Get the front node in the queue
        q.pop();
        cout << "Visited node: " << node << endl; // Process the current node

        // Visit all unvisited neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) { // Check if neighbor has been visited
                visited[neighbor] = true; // Mark neighbor as visited
                q.push(neighbor); // Enqueue the neighbor
            }
        }
    }
}

int main() {
    // Graph adjacency list
    vector<vector<int>> adj = {
        {1, 4},        // Node 0 is connected to nodes 1 and 4
        {0, 2, 3, 4},  // Node 1 is connected to nodes 0, 2, 3, and 4
        {1, 3},        // Node 2 is connected to nodes 1 and 3
        {1, 2, 4},     // Node 3 is connected to nodes 1, 2, and 4
        {0, 1, 3}      // Node 4 is connected to nodes 0, 1, and 3
    };

    BFS(adj, 0); // Start BFS from node 0
    return 0;
}
