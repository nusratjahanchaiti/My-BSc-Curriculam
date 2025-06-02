/*
     0----->1----->2
     ^      |      |
     |      v      v
     4<-----3<-----5

 */

#include <iostream>
#include <vector>    // Include the vector library to store adjacency lists and SCCs
#include <stack>     // Include the stack library to store finishing times
#include <algorithm> // Include algorithm for fill() to reset visited vector
using namespace std;

//Perform DFS on the original graph and store the finishing order of vertices.
void dfs1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finishStack) {
    visited[u] = true;    // Mark the current node as visited

    for (int v : adj[u]) { // Visit all the adjacent vertices of the current vertex
        if (!visited[v]) {  // If the neighbor is not visited
            dfs1(v, adj, visited, finishStack); // Recursively visit the unvisited nodes
        }
    }
    finishStack.push(u); // After visiting all the neighbors, push the current vertex to the stack
}

//Perform DFS on the reversed graph and identify SCCs.
void dfs2(int u, vector<vector<int>>& reversedAdj, vector<bool>& visited, vector<int>& scc) {
    visited[u] = true; // Mark the current node as visited
    scc.push_back(u);  // Add the current node to the current SCC

    // Visit all the adjacent vertices of the current vertex in the reversed graph
    for (int v : reversedAdj[u]) {
        if (!visited[v]) {     // Check if the neighbor has been visited
            dfs2(v, reversedAdj, visited, scc); // Recursively visit the unvisited nodes
        }
    }
}

int main() {
    int V = 6; // Number of vertices in the graph (nodes 0 to 5)

    // Initialize the adjacency list for the original graph
    vector<vector<int>> adj = {
        {1},         // Node 0 -> Node 1
        {2, 3},      // Node 1 -> Node 2, Node 3
        {},          // Node 2 -> (no outgoing edges)
        {4, 5},      // Node 3 -> Node 4, Node 5
        {},          // Node 4 -> (no outgoing edges)
        {1, 2}       // Node 5 -> Node 1, Node 2
    };

    // Find the transpose (reverse) of the graph.
    vector<vector<int>> reversedAdj(V); // To store the reversed graph
    for (int u = 0; u < V; u++) { // Reverse all edges in the original graph
        for (int v : adj[u]) {
            reversedAdj[v].push_back(u); // Reverse the direction of edges
        }
    }

    //Perform DFS on the original graph to get the finishing order.
    vector<bool> visited(V, false); // Keep track of visited nodes in the original graph
    stack<int> finishStack;         // Stack to store vertices in the order of their finishing times

    // Run DFS for all nodes that are not yet visited
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, finishStack); // Perform DFS and fill the stack with finishing order
        }
    }

    //Perform DFS on the reversed graph in the order of the stack.
    fill(visited.begin(), visited.end(), false); // Reset visited array for reversed DFS

    //Process each vertex in the stack in reverse order.
    vector<vector<int>> sccs; // To store the SCCs
    while (!finishStack.empty()) {
        int u = finishStack.top();  // Get the vertex from the stack
        finishStack.pop();          // Remove the vertex from the stack

        if (!visited[u]) { // If the vertex hasn't been visited in the reversed DFS
            vector<int> scc; // To store a single SCC
            dfs2(u, reversedAdj, visited, scc); // Perform DFS on the reversed graph
            sccs.push_back(scc); // Store the found SCC
        }
    }

    // Print the SCCs
    cout << "Strongly Connected Components (SCCs):" << endl;
    for (const auto& scc : sccs) {
        for (int node : scc) {
            cout << node << " "; // Print each node in the SCC
        }
    cout << endl; // Print each SCC in a new line
    }
return 0;  // Return 0 to indicate successful execution
}
