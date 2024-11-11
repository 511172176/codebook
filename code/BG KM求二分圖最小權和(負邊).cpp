#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

#define MAXN 102
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m, a[MAXN][MAXN], lx[MAXN], ly[MAXN], slack[MAXN], maty[MAXN];
int lenx, leny;
bool vx[MAXN], vy[MAXN];
char map[MAXN][MAXN];

bool search(int u) {

    int i, t;
    vx[u] = 1;
    for (int i = 0; i < leny; ++i) {
        if (!vy[i]) {
            int t = lx[u] + ly[i] - a[u][i];
            if (t == 0) {
                vy[i] = 1;
                if (maty[i] == -1 || search(maty[i])) {
                    maty[i] = u;
                    return 1;
                }
            }
            else if (slack[i] > t) {
                slack[i] = t;
            }
        }
    }
    return 0;
}

int KM() {
    int i, j, ans = 0;
    for (i = 0; i < lenx; ++i) {
        lx[i] = -INT_MAX;
        for (j = 0; j < leny; ++j) {
            lx[i] = max(lx[i], a[i][j]);
        }
    }
    memset(maty, -1, sizeof(maty));
    memset(ly, 0, sizeof(ly));
    for (i = 0; i < lenx; ++i) {
        fill(slack, slack + leny, INT_MAX);
        while (1) {
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            if (search(i)) break;
            int d = INT_MAX;
            for (j = 0; j < leny; ++j) {
                if (!vy[j] && d > slack[j]) d = slack[j];
            }
            for (j = 0; j < lenx; ++j) {
                if (vx[j]) lx[j] -= d;
            }
            for (j = 0; j < leny; ++j) {
                if (vy[j]) ly[j] += d;
            }
        }
    }
    for (i = 0; i < leny; ++i) {
        if (maty[i] != -1) ans += a[maty[i]][i];
    }
    return -ans;
}

int main() {
    int i, j;
    while (~scanf("%d%d", &n, &m) && n + m) {
        lenx = leny = 0;
        for (i = 0; i < n; ++i) {
            scanf("%s", map[i]);
            for (j = 0; j < m; ++j) {
                if (map[i][j] == 'H') {
                    lx[lenx] = i;
                    slack[lenx++] = j;
                } else if (map[i][j] == 'm') {
                    ly[leny] = i;
                    maty[leny++] = j;
                }
            }
        }
        for (i = 0; i < lenx; ++i) {
            for (j = 0; j < leny; ++j) {
                a[i][j] = -abs(lx[i] - ly[j]) - abs(slack[i] - maty[j]);
            }
        }
        printf("%d\n", KM());
    }
    return 0;
}
