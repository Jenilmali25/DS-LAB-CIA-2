#include <iostream>
#include <queue>
using namespace std;

// Change the function parameter to accept a pointer to an array
void bfs(int (*adj)[100], int start, int n) {
    int i = start, j;
    queue<int> q;
    int vis[n] = {0}; // Visited array

    cout << "BFS Order: "; // Output header
    cout << i + 1 << " "; // Print starting node (convert to 1-based indexing)
    vis[i] = 1;

    q.push(i);
    while (!q.empty()) {
        i = q.front();
        q.pop();
        for (j = 0; j < n; j++) { // Iterate through all vertices
            if (adj[i][j] == 1 && vis[j] == 0) {
                cout << j + 1 << " "; // Print visited node (convert to 1-based indexing)
                vis[j] = 1;
                q.push(j);
            }
        }
    }
    cout << endl; // New line after BFS output
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
    
    // Convert 1-based index input to 0-based index for internal processing
    bfs(adj, start - 1, n); // Call bfs with adjusted index
    return 0;
}

