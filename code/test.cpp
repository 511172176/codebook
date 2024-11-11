#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

const int MAXN = 100; // 最大節點數

// 深度優先搜尋 (DFS)：檢查從 current 到 target 是否可達
bool is_reachable(int current, int target, int N, int g[][MAXN], bool visited[]) {
    if (current == target) return true;  // 如果到達目標節點，返回 true
    visited[current] = true;
    for (int i = 0; i < N; i++) {
        if (g[current][i] && !visited[i]) {  // 如果有連接且未訪問，遞迴檢查
            if (is_reachable(i, target, N, g, visited)) return true;
        }
    }
    return false;
}

// 檢查並構建拓樸排序
bool topological_sort(int N, int g[][MAXN], vector<int>& in_degree, vector<int>& result) {
    vector<int> in_copy = in_degree;  // 複製 in-degree 以供修改
    queue<int> Q;
    result.clear();

    // 初始入度為 0 的節點入佇列
    for (int i = 0; i < N; i++) {
        if (in_copy[i] == 0) Q.push(i);
    }

    bool multiple_sequences = false; // 用於檢查多個拓樸序

    while (!Q.empty()) {
        if (Q.size() > 1) multiple_sequences = true; // 多個節點入度為 0

        int current = Q.front();
        Q.pop();
        result.push_back(current);

        // 更新鄰居的入度
        for (int i = 0; i < N; i++) {
            if (g[current][i]) {
                in_copy[i]--;
                if (in_copy[i] == 0) Q.push(i);
            }
        }
    }

    // 判斷是否完成唯一排序
    return result.size() == N && !multiple_sequences;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    while (cin >> N >> K) {
        if (N == 0 && K == 0) break; // 當 N 與 K 都為 0 時結束

        // 初始化相鄰矩陣和入度計數
        int g[MAXN][MAXN];
        memset(g, 0, sizeof(g));
        vector<int> in_degree(N, 0);

        bool determined = false;
        bool inconsistent = false;
        string relation;

        for (int i = 0; i < K; i++) {
            cin >> relation;

            char a = relation[0];
            char b = relation[2];
            char op = relation[1];
            int x, y;

            // 根據關係設定方向
            if (op == '<') {
                x = a - 'A';
                y = b - 'A';
            } else { // op == '>'
                x = b - 'A';
                y = a - 'A';
            }

            // 使用 DFS 檢查是否形成迴圈
            bool visited[MAXN];
            memset(visited, false, sizeof(visited));
            if (is_reachable(y, x, N, g, visited)) {
                cout << "Inconsistency found after " << (i + 1) << " relations." << endl;
                for (int j = i + 1; j < K; j++) cin >> relation;  // 忽略剩餘關係
                inconsistent = true;
                break;
            }

            // 新增有向邊 x -> y 並更新入度
            g[x][y] = 1;
            in_degree[y]++;

            // 嘗試拓樸排序
            vector<int> result;
            if (topological_sort(N, g, in_degree, result)) {
                cout << "Sorted sequence determined after " << (i + 1) << " relations: ";
                for (int node : result) cout << char('A' + node);
                cout << "." << endl;

                for (int j = i + 1; j < K; j++) cin >> relation;  // 忽略剩餘關係
                determined = true;
                break;
            }
        }

        // 若無法判定唯一序列或發現不一致
        if (!inconsistent && !determined) {
            cout << "Sorted sequence cannot be determined." << endl;
        }
    }

    return 0;
}
