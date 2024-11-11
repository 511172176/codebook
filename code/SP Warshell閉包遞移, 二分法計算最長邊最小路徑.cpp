//UVA534
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

const int MAX_N = (1 << 9) + 1;
double L[MAX_N][MAX_N];  // 距離矩陣
bool con[MAX_N][MAX_N];  // 連接矩陣，用於表示節點之間是否可達

// 計算青蛙距離的函式（Floyd-Warshall 閉包遞移 + 二分法）
double calculateFrogDistance(int N, const vector<double>& x, const vector<double>& y) {
    // 計算距離矩陣 L
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            L[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
        }
    }

    // 使用二分法找最小的最大距離，使得第一塊石頭和第二塊石頭連通
    double l = 0, r = 1e5;
    while (r - l > 1e-5) { // 精度為 1e-5
        double mid = (l + r) / 2;

        // 初始化連接矩陣，判斷在當前 mid 距離下的節點連通情況
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                con[i][j] = (L[i][j] <= mid);
            }
        }

        // Floyd-Warshall 演算法，計算所有節點之間的可達性
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    con[i][j] = con[i][j] || (con[i][k] && con[k][j]);
                }
            }
        }

        // 檢查第一和第二塊石頭是否連通
        if (con[0][1]) {
            r = mid;
        } else {
            l = mid;
        }
    }

    return l; // 返回最小的最大距離，即青蛙距離
}

int main() {
    int N, testCase = 0;
    while (cin >> N && N != 0) {
        vector<double> x(N), y(N);

        // 讀取每塊石頭的座標
        for (int i = 0; i < N; ++i) {
            cin >> x[i] >> y[i];
        }

        // 計算並輸出青蛙距離
        double frogDistance = calculateFrogDistance(N, x, y);

        // 輸出結果，保留三位小數
        cout << "Scenario #" << ++testCase << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << frogDistance << endl;
        cout << endl;
    }
    return 0;
}