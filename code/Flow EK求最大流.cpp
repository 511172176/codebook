//POJ1459
#include <stdio.h>
#include <math.h>
#include <memory.h>

int n, np, nc, m, s, t;
int fa[104], q[104], f[104][104], c[104][104]; // fa[]儲存路徑，q[]為佇列，f[i][j]記錄流量，c[i][j]記錄容量

// Edmonds-Karp 演算法，用來計算最大流
int calculateMaxFlow() {
    int ans = 0; // 儲存最大流結果
    while (1) {
        int qs = 0, qt = 1;
        q[qt] = s;
        memset(fa, 0, sizeof(fa)); // 初始化增廣路徑
        fa[s] = s;                 // 起點的前驅設為自己
        
        // BFS 尋找增廣路徑
        while (qs < qt && fa[t] == 0) {
            int i = q[++qs];
            for (int j = 1; j <= t; j++) {
                if (fa[j] == 0) { // 若節點 j 尚未被訪問
                    if (f[i][j] < c[i][j]) { // 正向邊有剩餘容量
                        fa[j] = i;           // 設定前驅節點
                        q[++qt] = j;         // 將節點 j 加入佇列
                    } else if (f[j][i] > 0) { // 反向邊有可減少流量
                        fa[j] = -i;          // 使用負號表示反向流
                        q[++qt] = j;
                    }
                }
            }
        }
        
        // 若無增廣路則結束
        if (fa[t] == 0) break;

        // 找到增廣路中最小容量的邊
        int doo = 1000000000;
        int i = t;
        while (i != s) {
            int d;
            if (fa[i] > 0) {
                d = c[fa[i]][i] - f[fa[i]][i];
            } else {
                d = f[i][-fa[i]];
            }
            if (d < doo) doo = d;
            i = abs(fa[i]);
        }
        
        // 沿增廣路增加流量
        ans += doo;
        i = t;
        while (i != s) {
            if (fa[i] > 0) {
                f[fa[i]][i] += doo; // 正向增加流量
            } else {
                f[i][-fa[i]] -= doo; // 反向減少流量
            }
            i = abs(fa[i]);
        }
    }
    return ans; // 返回最大流
}

int main() {
    int i, u, v, cc;
    while (scanf("%d%d%d%d", &n, &np, &nc, &m) == 4) { // 輸入節點數、源點數、匯點數和邊數
        s = n + 2; // 設置虛擬源點編號
        t = n + 1; // 設置虛擬匯點編號
        memset(f, 0, sizeof(f)); // 初始化流量矩陣
        memset(c, 0, sizeof(c)); // 初始化容量矩陣

        // 讀取邊的資訊，並設定容量
        for (i = 1; i <= m; i++) {
            while (getchar() != '(');
            scanf("%d,%d)%d", &u, &v, &cc);
            c[u + 1][v + 1] = cc;
        }

        // 讀取源點資訊，將虛擬源點連接到每個源點
        for (i = 1; i <= np; i++) {
            while (getchar() != '(');
            scanf("%d)%d", &u, &cc);
            c[s][u + 1] = cc;
        }

        // 讀取匯點資訊，將每個匯點連接到虛擬匯點
        for (i = 1; i <= nc; i++) {
            while (getchar() != '(');
            scanf("%d)%d", &u, &cc);
            c[u + 1][t] = cc;
        }

        // 執行 Edmonds-Karp 演算法，並輸出最大流
        printf("%d\n", calculateMaxFlow());
    }
    return 0;
}