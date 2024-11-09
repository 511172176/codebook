#include <iostream>
#include <cstring>
using namespace std;

int map[105][105];     // Grid map indicating oil and empty spots
int vis[105][105];     // Visited marker array
int n, m;              // Rows and columns of the grid

// DFS function to explore connected components
void dfs(int x, int y) {
    vis[x][y] = 1;     // Mark current cell as visited

    // Explore all 8 possible directions
    if (x + 1 < n && y < m && !vis[x + 1][y] && map[x + 1][y]) dfs(x + 1, y);
    if (x - 1 >= 0 && y < m && !vis[x - 1][y] && map[x - 1][y]) dfs(x - 1, y);
    if (x < n && y + 1 < m && !vis[x][y + 1] && map[x][y + 1]) dfs(x, y + 1);
    if (x < n && y - 1 >= 0 && !vis[x][y - 1] && map[x][y - 1]) dfs(x, y - 1);
    if (x + 1 < n && y + 1 < m && !vis[x + 1][y + 1] && map[x + 1][y + 1]) dfs(x + 1, y + 1);
    if (x - 1 >= 0 && y - 1 >= 0 && !vis[x - 1][y - 1] && map[x - 1][y - 1]) dfs(x - 1, y - 1);
    if (x + 1 < n && y - 1 >= 0 && !vis[x + 1][y - 1] && map[x + 1][y - 1]) dfs(x + 1, y - 1);
    if (x - 1 >= 0 && y + 1 < m && !vis[x - 1][y + 1] && map[x - 1][y + 1]) dfs(x - 1, y + 1);
}

// Function to initialize visited array to zero
void init() {
    memset(vis, 0, sizeof(vis));
}

int main() {
    char ch;
    while (cin >> n >> m) {       // Read grid dimensions
        if (n == 0 && m == 0) break;

        init();                   // Clear the visited markers

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> ch;        // Read each cell of the grid
                if (ch == '*')
                    map[i][j] = 0; // Mark empty spot
                else
                    map[i][j] = 1; // Mark oil spot
            }
        }

        int count = 0;            // Initialize oil deposit count

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && map[i][j]) {
                    dfs(i, j);    // Run DFS from each unvisited oil spot
                    count++;      // Increment oil deposit count
                }
            }
        }
        cout << count << endl;    // Output the count of different oil deposits
    }
    return 0;
}
