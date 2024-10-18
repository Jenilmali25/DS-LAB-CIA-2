#include <iostream>
#include <stack>
using namespace std;

// DFS function using stack (iterative approach)
void dfs(int adj[][100], int start, int n) {
    bool vis[100] = {false}; // Visited array
    stack<int> s; // Stack for DFS

    // Push the starting vertex onto the stack
    s.push(start);
    
    cout << "DFS Order: "; // Output header

    while (!s.empty()) {
        int curr = s.top();
        s.pop();
        
        // If the current vertex is not visited
        if (!vis[curr]) {
            vis[curr] = true; // Mark as visited
            cout << curr + 1 << " "; // Print node in 1-based indexing

            // Push adjacent vertices onto the stack
            for (int j = n - 1; j >= 0; j--) { // Reverse order to maintain order in output
                if (adj[curr][j] == 1 && !vis[j]) {
                    s.push(j);
                }
            }
        }
    }
    cout << endl; // New line after DFS output
}

int main() {
    int n;    
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;
    int adj[100][100] = {0}; // Declare a fixed size array for the adjacency matrix
    cout << "Enter the adjacency matrix:" << endl; // Prompt for adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];    
        }    
    }
    
    int start;
    cout << "Enter the starting vertex: "; // Prompt for starting vertex
    cin >> start;
    
    dfs(adj, start - 1, n); // Convert to 0-based index for internal processing
    return 0;
}

