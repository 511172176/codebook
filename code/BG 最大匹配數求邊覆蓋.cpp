#include <iostream>
#include <cstring>
using namespace std;

const int V = 1100;

int n, m, k, x, y, pre[V];
bool v[V], a[V][V];

bool dfs(int i) {
    for (int j = 1; j <= m; j++) {
        if (!v[j] && a[i][j]) {  // check if j is unvisited and there is an edge between i and j
            v[j] = 1;            // mark j as visited
            if (pre[j] == 0 || dfs(pre[j])) {  // if j has no previous match or previous match can find an alternate path
                pre[j] = i;                   // set (i, j) as a match
                return 1;                     // matching success
            }
        }
    }
    return 0;  // matching failed
}

int main() {
    cin >> n >> m >> k;  // input number of representatives from A and B, and the number of pairs
    memset(a, 0, sizeof(a));       // initialize adjacency matrix for bipartite graph
    memset(pre, 0, sizeof(pre));    // initialize matching storage array

    for (int i = 1; i <= k; i++) {
        cin >> x >> y;  // input pair representing relationship between A's representative x and B's representative y
        a[x][y] = 1;    // mark the relationship as an edge
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(v, 0, sizeof(v));  // initialize visit array for each representative
        if (dfs(i)) ans++;        // if representative i can be matched, increment match count
    }

    cout << n + m - ans << endl;  // output minimum number of telephone lines required, N + M - max matching
    return 0;
}
