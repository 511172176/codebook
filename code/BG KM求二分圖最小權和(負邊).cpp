//POJ2195
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

#define MAXN 102
#define max(x, y) ((x) > (y) ? (x) : (y))

int a[MAXN][MAXN];         // 權重矩陣
int lx[MAXN], ly[MAXN];    // X 集合和 Y 集合的標籤（用於 KM 演算法）
int slack[MAXN], maty[MAXN]; // slack 用於減少更新量，maty 用於紀錄 Y 集合的匹配情況
bool vx[MAXN], vy[MAXN];   // 標記陣列，用於記錄當前匹配過程中的 X 和 Y 集合訪問情況
int lenx, leny;            // X 集合和 Y 集合的有效元素數量

// DFS 搜索增廣路，試圖找到最佳匹配
bool search(int u) {
    vx[u] = 1;
    for (int i = 0; i < leny; ++i) {
        if (!vy[i]) {
            int t = lx[u] + ly[i] - a[u][i];  // 計算是否符合增廣路條件
            if (t == 0) {                     // 若滿足匹配條件
                vy[i] = 1;
                if (maty[i] == -1 || search(maty[i])) {
                    maty[i] = u;              // 設定 (u, i) 為匹配
                    return true;              // 匹配成功
                }
            } else if (slack[i] > t) {
                slack[i] = t;                 // 更新 slack 值
            }
        }
    }
    return false;                             // 匹配失敗
}

// KM 演算法，計算二分圖的最小權和
int minWeightBipartiteMatching(int lenx, int leny) {
    memset(maty, -1, sizeof(maty));   // 初始化 Y 集合的匹配狀態
    memset(ly, 0, sizeof(ly));        // 初始化 Y 集合的標籤
    for (int i = 0; i < lenx; ++i) {
        lx[i] = -INT_MAX;
        for (int j = 0; j < leny; ++j) {
            lx[i] = max(lx[i], a[i][j]); // 初始化 X 集合的標籤為最大權重
        }
    }

    // 對每個 X 集合的元素進行匹配
    for (int i = 0; i < lenx; ++i) {
        fill(slack, slack + leny, INT_MAX); // 初始化 slack 值
        while (1) {
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            if (search(i)) break;          // 若成功匹配則跳出迴圈
            int d = INT_MAX;
            for (int j = 0; j < leny; ++j) {
                if (!vy[j] && d > slack[j]) d = slack[j]; // 找到最小的 slack 值
            }
            for (int j = 0; j < lenx; ++j) {
                if (vx[j]) lx[j] -= d;      // 更新 X 集合的標籤
            }
            for (int j = 0; j < leny; ++j) {
                if (vy[j]) ly[j] += d;      // 更新 Y 集合的標籤
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < leny; ++i) {
        if (maty[i] != -1) ans += a[maty[i]][i]; // 計算最小權和
    }
    return -ans; // 因為 a[i][j] 存的是負權重，所以返回 -ans 作為最小權和
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m) && n + m) {
        lenx = leny = 0;
        char map[MAXN][MAXN];
        int lx_pos[MAXN], ly_pos[MAXN];

        // 讀取輸入並建立二分圖
        for (int i = 0; i < n; ++i) {
            scanf("%s", map[i]);
            for (int j = 0; j < m; ++j) {
                if (map[i][j] == 'H') {
                    lx_pos[lenx] = i;
                    slack[lenx++] = j;
                } else if (map[i][j] == 'm') {
                    ly_pos[leny] = i;
                    maty[leny++] = j;
                }
            }
        }

        // 初始化權重矩陣 a[i][j]
        for (int i = 0; i < lenx; ++i) {
            for (int j = 0; j < leny; ++j) {
                a[i][j] = -abs(lx_pos[i] - ly_pos[j]) - abs(slack[i] - maty[j]);
            }
        }

        // 使用 KM 演算法計算最小權和
        printf("%d\n", minWeightBipartiteMatching(lenx, leny));
    }
    return 0;
}