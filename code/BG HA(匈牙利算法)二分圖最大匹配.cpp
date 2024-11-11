#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[110][310];
int n, m, vis[310], pre[310];

bool dfs(int x) {
    int t;
    for (t = 1; t <= m; ++t) {
        if (a[x][t] && !vis[t]) {  // if there is an edge and t is not visited
            vis[t] = 1;             // mark t as visited
            if (pre[t] == 0 || dfs(pre[t])) {  // if t has no previous match or previous match can find an alternate path
                pre[t] = x;                    // set (x, t) as a match
                return true;                   // matching success
            }
        }
    }
    return false;  // matching failed
}

int main() {
    int T, i, t, j, s;
    scanf("%d", &T);  // input number of test cases
    while (T--) {
        scanf("%d%d", &n, &m);  // input number of courses and students
        memset(a, 0, sizeof(a));    // initialize adjacency matrix for bipartite graph
        memset(pre, 0, sizeof(pre));  // initialize matching storage array

        for (i = 1; i <= n; ++i) {
            scanf("%d", &t);  // input number of students corresponding to each course
            while (t--) {
                scanf("%d", &j);  // input each student
                a[i][j] = 1;      // mark relation between course i and student j as an edge
            }
        }

        s = 0;
        for (i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof(vis));  // initialize visit array for each course
            if (dfs(i)) s++;  // if course i can be matched, increment match count
        }

        if (s == n) printf("YES\n");  // if maximum match count equals course count, team can be formed
        else printf("NO\n");          // otherwise, team formation fails
    }
    return 0;
}
