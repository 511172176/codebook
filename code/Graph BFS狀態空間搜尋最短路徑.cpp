//POJ3126
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 定義節點結構，包含當前數字和步數
struct node {
    int k, step;
    node(int k_val, int step_val) : k(k_val), step(step_val) {}
};

// 使用埃拉托斯特尼篩法產生 10000 以內的質數
const int power10_arr[4] = {1000, 100, 10, 1};  // 用於數位位置變換
bool is_prime[10000], visited[10000];           // 儲存質數和訪問狀態

// 初始化篩法產生質數
void makeSieve(int n) {
    memset(is_prime, 0, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 1;  // 0 和 1 不是質數
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 1;   // 標記 i 的所有倍數為非質數
        }
    }
}

// 改變 x 的第 pos 位數字為 new_digit，並返回新數字
int changeDigit(int x, int pos, int new_digit) {
    int digits[4] = { x / 1000, (x / 100) % 10, (x / 10) % 10, x % 10 };
    digits[pos - 1] = new_digit;
    return digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
}

// 使用 BFS 搜索 x 到 y 的最短路徑，僅允許變換為質數
int bfsShortestPath(int x, int y) {
    // 初始化佇列和訪問狀態
    queue<node> q;
    memset(visited, 0, sizeof(visited));
    
    q.push(node(x, 0));
    visited[x] = 1;

    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        if (cur.k == y) return cur.step;  // 找到目標數字時返回步數

        // 遍歷每一位數進行數字變換
        for (int i = 1; i <= 4; i++) {  // i 表示數位 (千位、百位、十位、個位)
            for (int j = 0; j <= 9; j++) {
                // 跳過不合法的情況：千位不為 0 和當前數字不變的情況
                if ((i == 1 && j == 0) || ((cur.k / power10_arr[i - 1]) % 10) == j)
                    continue;

                int new_number = changeDigit(cur.k, i, j);

                // 判斷新數字是否為質數，且在範圍內，且未被訪問過
                if (new_number >= 1000 && new_number <= 9999 && !is_prime[new_number] && !visited[new_number]) {
                    visited[new_number] = 1;
                    q.push(node(new_number, cur.step + 1)); // 新數字加入佇列
                }
            }
        }
    }
    return -1; // 無法從 x 轉換為 y 時，返回 -1
}

// 主程式，處理多組測試案例
void processCases() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int start, end;
        cin >> start >> end;

        // 驗證輸入是否在範圍內且為質數
        if (start < 1000 || start > 9999 || end < 1000 || end > 9999 || is_prime[start] || is_prime[end]) {
            cout << "Impossible" << endl;
        } else {
            int result = bfsShortestPath(start, end);
            if (result >= 0)
                cout << result << "\n";
            else
                cout << "Impossible\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    makeSieve(9999);       // 初始化質數篩法
    processCases();        // 處理多組測試案例
    return 0;
}
