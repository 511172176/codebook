#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_N 1010
#define MAX_M 2010
#define INF 1e9

using namespace std;

int w[MAX_N][MAX_N];     // Weight matrix for the graph
int d[MAX_N];            // Distance array for Dijkstra's algorithm
bool visited[MAX_N];     // Visited array for Dijkstra's algorithm
int n, m;                // n = number of nodes, m = number of edges

void dijkstra(int s) {   // Dijkstra's algorithm starting from node s
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;      // Initialize all distances to infinity
        visited[i] = false; // Mark all nodes as unvisited
    }
    d[s] = 0;            // Starting node distance is 0

    for (int i = 1; i <= n; ++i) {
        int x = -1;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && (x == -1 || d[j] < d[x])) x = j;
        }
        visited[x] = true;

        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && w[x][j] != INF) {
                d[j] = min(d[j], d[x] + w[x][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d", &m, &n); // Input the number of edges and nodes
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            w[i][j] = INF; // Initialize weight matrix with INF
        }
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c); // Input edge endpoints and weight
        if (w[a][b] > c) w[a][b] = w[b][a] = c; // Update to minimum weight for undirected graph
    }

    dijkstra(1); // Run Dijkstra's algorithm starting from node 1

    printf("%d\n", d[n]); // Output the shortest path distance to node n
    return 0;
}
