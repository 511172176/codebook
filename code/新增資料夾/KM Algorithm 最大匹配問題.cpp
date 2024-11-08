// KM Algorithm (最大匹配問題)

int Lx[maxn], Ly[maxn];  // 頂標和底標
int W[maxn][maxn];  // 權重矩陣
bool S[maxn], T[maxn];  // 記錄 S 和 T 集合
int n;  // 節點數

void update() {
    int a = 1 << 30;  // 初始最小差值設置為無限大
    for (int i = 1; i <= n; i++) {
        if (S[i]) {
            for (int j = 1; j <= n; j++) {
                if (!T[j]) {
                    a = min(a, Lx[i] + Ly[j] - W[i][j]);  // 更新最小差值
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (S[i]) Lx[i] -= a;  // 更新頂標
        if (T[i]) Ly[i] += a;  // 更新底標
    }
}
