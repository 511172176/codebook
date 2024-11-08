// 高斯消去法計算矩陣的秩
int rank(Matrix A, int m, int n) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        int r = i;
        for (int k = i; k < m; k++) {
            if (A[k][j]) {
                r = k;
                break;
            }
        }
        if (A[r][j]) {
            if (r != i) {
                for (int k = 0; k <= n; k++) swap(A[r][k], A[i][k]);
            }
            for (int u = i + 1; u < m; u++) {
                if (A[u][j]) {
                    for (int k = i; k <= n; k++) A[u][k] ^= A[i][k];
                }
            }
            i++;
        }
        j++;
    }
    return i;  // 返回矩陣的秩
}
