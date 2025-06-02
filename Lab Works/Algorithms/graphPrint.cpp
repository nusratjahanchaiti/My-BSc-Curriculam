 /*     0
       / \
      1   3
     / \   \
    2---4---5
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

int numOfVertices = 6; // Number of vertices

    // Initialize the adjacency list for the graph
vector<vector<int>> adj = {
    {1, 3},        // Node 0 is connected to nodes 1 and 3
    {0, 2, 4},     // Node 1 is connected to nodes 0, 2, and 4
    {1, 4},        // Node 2 is connected to nodes 1 and 4
    {0, 5},        // Node 3 is connected to nodes 0 and 5
    {1, 2, 5},     // Node 4 is connected to nodes 1, 2, and 5
    {3, 4}         // Node 5 is connected to nodes 3 and 4
    };

    // Print the adjacency list
for(int i = 0; i < numOfVertices  ; i++) {
 cout << "NODE " << i <<  " connected to -> ";
    for (int neighbor : adj[i]) {       // Iterate through neighbors of node i
            cout << neighbor << " ";
        }
        cout << endl;       // Newline after printing all neighbors of node i
    }

    return 0;        // Return statement indicating successful completion
}
