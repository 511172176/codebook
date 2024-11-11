#include <stdio.h>
#include <math.h>
#include <memory.h>

int n, np, nc, m, s, t;
int fa[104], q[104], f[104][104], c[104][104];  // fa[]儲存路徑，q[]為佇列，f[i][j]記錄流量，c[i][j]記錄容量

void Edmonds_Karp() {  // Edmonds-Karp演算法求最大流
    int qs, qt, d, doo, i, j, ans = 0;
    fa[t] = 1;
    while (fa[t] != 0) {  // 若增廣路徑存在
        qs = 0; qt = 1;
        q[qt] = s;
        memset(fa, 0, sizeof(fa));  // 初始化增廣路徑
        fa[s] = s;
        while (qs < qt && fa[t] == 0) {
            i = q[++qs];
            for (j = 1; j <= t; j++) {
                if (fa[j] == 0) {
                    if (f[i][j] < c[i][j]) {  // 若(i, j)的流量可增加
                        fa[j] = i;
                        q[++qt] = j;
                    }
                    else if (f[j][i] > 0) {  // 若(i, j)的反向流量可減少
                        fa[j] = -i;
                        q[++qt] = j;
                    }
                }
            }
        }
        if (fa[t] != 0) {  // 如果找到增廣路徑
            doo = 1000000000;
            i = t;
            while (i != s) {  // 從終點逆向尋找增廣路徑中最小容量
                if (fa[i] > 0) {
                    if((d = c[fa[i]][i] - f[fa[i]][i]) < doo)
                        doo = d;
                } else {
                    if (f[i][-fa[i]] < doo)
                        doo = f[i][-fa[i]];
                }
                i = abs(fa[i]);
            }
            ans += doo;
            i = t;
            while (i != s) {  // 增加增廣路徑上流量
                if (fa[i] > 0)
                    f[fa[i]][i] += doo;
                else
                    f[i][-fa[i]] -= doo;
                i = abs(fa[i]);
            }
        }
    }
    printf("%d\n", ans);  // 輸出最大流
}

int main() {
    int i, u, v, cc;
    while (scanf("%d%d%d%d", &n, &np, &nc, &m) == 4) {  // 輸入節點數、源點數、匯點數和邊數
        s = n + 2; t = n + 1;
        memset(f, 0, sizeof(f));
        memset(c, 0, sizeof(c));
        for (i = 1; i <= m; i++) {  // 讀取邊的資訊
            while(getchar() != '(');
            scanf("%d,%d)%d", &u, &v, &cc);
            c[u + 1][v + 1] = cc;
        }
        for (i = 1; i <= np; i++) {  // 讀取每個源點的流量容量
            while (getchar() != '(');
            scanf("%d)%d", &u, &cc);
            c[s][u + 1] = cc;
        }
        for (i = 1; i <= nc; i++) {  // 讀取每個匯點的流量容量
            while (getchar() != '(');
            scanf("%d)%d", &u, &cc);
            c[u + 1][t] = cc;
        }
        Edmonds_Karp();  // 執行 Edmonds-Karp 演算法求最大流
    }
    return 0;
}
