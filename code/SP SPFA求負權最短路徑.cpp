#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 501;
const int INF = 1e9;           // Define a large constant for infinity
int map[MAX][MAX];              // Adjacency matrix to store graph weights
int dis[MAX];                   // Distance array
int n, m, w, s, e, t;           // Variables for nodes, edges, and endpoints
bool spfa();                    // Function declaration for SPFA algorithm

// SPFA function to detect if there is a negative cycle in the graph
bool spfa() {
    bool flag[MAX] = {0};       // Flags to mark nodes in the queue
    int count[MAX] = {0};       // Counter for each node's occurrences in queue
    queue<int> q;
    q.push(s);                  // Start from source node
    dis[s] = 0;                 // Distance to source is 0
    int curr;
    int i;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if(map[curr][i]<100000)
            {
                if(dis[i] > map[curr][i] + dis[curr])
                {
                    dis[i] = map[curr][i] + dis[curr];
                    if(flag[i] == 0)
                        q.push(i);
                    count[i]++;
                    flag[i] = 1;
                    if(count[i]>=n)
                        return 0;
                }
            }
        }
        flag[curr] = 0;
    }
    return true;
}

int main() {
    int f;
    scanf("%d", &f);
    while (f--) {
        // Reset arrays between test cases
        memset(dis, 63, sizeof(dis));      // Initialize distance array to a large number
        memset(map, 127, sizeof(map));

        scanf("%d %d %d", &n, &m, &w); // Read number of nodes, edges, and start/end points
        int i;
        for (i = 0; i < m; i++) {
            scanf("%d %d %d", &s, &e, &t);
                        // Update to the smallest weight if multiple edges exist
            map[s][e] = map[s][e]>t? t: map[s][e];
            map[e][s] = map[e][s]>t? t: map[e][s];
        }

        for (int i = 0; i < w; i++) {
            scanf("%d %d %d", &s, &e, &t);
            map[s][e] = -t;                // Set the edge with negative weight for wormhole
        }

        if (spfa())                        // Use SPFA to detect negative cycles
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
