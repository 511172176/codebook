//POJ1258
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 取得最小生成樹權重的函式（Prim 算法）
int calculateMSTWeightPrim(int n, const vector<vector<int>> &v) {
    int tot = 0;                       // 用於累計 MST 的總權重
    vector<int> dist(n, INT_MAX);       // 距離陣列，初始化為最大值
    vector<bool> use(n, false);         // 記錄節點是否已被加入 MST 的布林陣列

    dist[0] = 0; // 設定起始節點的距離為 0

    // 初始化從起始節點到其他節點的距離
    for (int i = 1; i < n; i++) {
        dist[i] = v[0][i];
    }

    // 主迴圈，用來擴展最小生成樹，直到包含所有節點
    for (int i = 1; i < n; i++) { // 擴展 MST 需要 n - 1 條邊
        int tmp = -1;

        // 線性掃描找出未加入 MST 的節點中距離最小的節點
        for (int k = 1; k < n; k++) {
            if (!use[k] && (tmp == -1 || dist[k] < dist[tmp])) {
                tmp = k;
            }
        }

        use[tmp] = true;       // 將選中的節點標記為已使用
        tot += dist[tmp];      // 累加選中邊的權重到 MST 的總權重

        // 更新距離陣列 dist，對於所有未加入 MST 的節點
        for (int k = 1; k < n; k++) {
            if (!use[k]) {
                dist[k] = min(dist[k], v[k][tmp]);
            }
        }
    }

    return tot; // 返回最小生成樹的總權重
}

int main() {
    int n;
    while (cin >> n) {  // 讀取節點數量
        vector<vector<int>> v(n, vector<int>(n)); // 鄰接矩陣表示圖
        // 讀取鄰接矩陣
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

        // 計算最小生成樹的權重
        int total_MST_weight = calculateMSTWeightPrim(n, v);

        // 輸出 MST 的總權重
        cout << total_MST_weight << endl;
    }

    return 0;
}