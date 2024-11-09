#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min(int i, int j) { // Return the index with the minimum value
    return i < j ? i : j;
}

int main() {
    int n;
    while (cin >> n) {
        int tot = 0;
        vector<vector<int>> v(n, vector<int>(n)); // Adjacency matrix for the graph
        vector<int> dist(n, INT_MAX); // Distance array, initialized to maximum
        vector<bool> use(n, false);   // Boolean array to mark visited nodes

        // Reading the adjacency matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

        dist[0] = 0; // Starting node has distance 0

        // Prim's algorithm to find MST
        for (int i = 1; i < n; i++) {
            dist[i] = v[0][i]; // Initialize the distance from the starting node
        }

        for (int i = 1; i < n; i++) { // Expand the MST with n - 1 edges
            int tmp = -1;
            for (int k = 1; k < n; k++) { // Find the minimum edge weight to add to MST
                if (!use[k] && (tmp == -1 || dist[k] < dist[tmp])) {
                    tmp = k;
                }
            }

            use[tmp] = true; // Mark the node as part of MST
            tot += dist[tmp]; // Add the minimum edge weight to the total weight

            // Update distances to nodes outside the MST
            for (int k = 1; k < n; k++) {
                if (!use[k]) {
                    dist[k] = min(dist[k], v[k][tmp]);
                }
            }
        }

        cout << tot << endl; // Output the total weight of the MST
    }

    return 0;
}
