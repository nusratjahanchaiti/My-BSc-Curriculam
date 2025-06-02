
     /*     4
         ^  |  ^
        /   v    \
       1 → 3 → 5
        \   ↑    /
         v /    v
            2

*/



#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to perform DFS and store the topological order
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& topoOrder) {
    visited[node] = true;  // Mark the current node as visited

    // Visit all the neighbors of the current node
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {  // If the neighbor has not been visited
            dfs(neighbor, adj, visited, topoOrder);  // Recursively visit the neighbor
        }
    }

    // After visiting all neighbors, push the node to the stack
    topoOrder.push(node);  // The node is now added to the topological order
}

// Function to perform Topological Sort
void topologicalSort(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);  // Keep track of visited nodes
    stack<int> topoOrder;  // Stack to store the topological order

    // Perform DFS for each node (starting from node 0 to V-1, since nodes are 0-based)
    for (int i = 0; i < V; i++) {  // Loop from 0 to V-1, to iterate all nodes
        if (!visited[i]) {  // If the node is not visited
            dfs(i, adj, visited, topoOrder);  // Start DFS from that node
        }
    }

    // Print the topological order (in reverse order of the stack)
    cout << "Topological Sort: ";
    while (!topoOrder.empty()) {
        cout << topoOrder.top() << " ";  // Print the top node in the stack
        topoOrder.pop();  // Remove the node from the stack
    }
    cout << endl;
}

int main() {
    int V = 6;  // Number of vertices in the graph (0 to 5)

    // Adjacency list representation of the graph
    // 0 → 2, 3, 4
    // 1 → 3
    // 2 → 5
    // 3 → 4, 5
    // 4 → 3
    // 5 → no outgoing edges
    vector<vector<int>> adj = {
        {2, 3, 4},  // Node 0 points to nodes 2, 3, and 4
        {3},        // Node 1 points to node 3
        {5},        // Node 2 points to node 5
        {4, 5},     // Node 3 points to nodes 4 and 5
        {3},        // Node 4 points to node 3
        {}          // Node 5 points to no node
    };

    // Perform topological sort on the graph
    topologicalSort(V, adj);

    return 0;
}
