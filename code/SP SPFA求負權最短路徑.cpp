//POJ3259
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 501;
const int INF = 1e9;           // 定義一個大常數作為無限大
int map[MAX][MAX];              // 鄰接矩陣，用來儲存圖的權重
int dis[MAX];                   // 距離陣列
int n, m, w, s, e, t;           // 節點數、邊數、起點和終點以及權重

// 使用 SPFA 演算法檢測圖中是否存在負環的函式
bool detectNegativeCycleUsingSPFA(int start) {
    bool flag[MAX] = {0};       // 標記節點是否在隊列中
    int count[MAX] = {0};       // 每個節點進入隊列的次數
    queue<int> q;
    q.push(start);              // 從起點開始
    dis[start] = 0;             // 起點的距離設為 0

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // 遍歷所有相鄰節點，更新最短距離
        for (int i = 1; i <= n; i++) {
            // 如果節點相連且存在有效邊
            if (map[curr][i] < INF) {
                // 檢查從當前節點到相鄰節點的最短距離
                if (dis[i] > map[curr][i] + dis[curr]) {
                    dis[i] = map[curr][i] + dis[curr]; // 更新最短距離
                    if (!flag[i]) {
                        q.push(i);        // 將相鄰節點加入隊列
                        flag[i] = true;   // 標記節點在隊列中
                    }
                    count[i]++;           // 記錄節點的進入次數

                    // 如果節點進入隊列次數超過節點數，則存在負環
                    if (count[i] >= n) return false;
                }
            }
        }
        flag[curr] = false;     // 將當前節點標記為不在隊列中
    }
    return true;                // 如果無負環，返回 true
}

int main() {
    int f;
    scanf("%d", &f);
    while (f--) {
        // 重置陣列
        memset(dis, 63, sizeof(dis));      // 初始化距離陣列為大值
        memset(map, 127, sizeof(map));     // 初始化鄰接矩陣為大值，表示無連接

        // 輸入節點、邊、起點和終點數
        scanf("%d %d %d", &n, &m, &w);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &s, &e, &t);
            // 若存在重邊，保留最小的權重
            map[s][e] = min(map[s][e], t);
            map[e][s] = min(map[e][s], t);
        }

        for (int i = 0; i < w; i++) {
            scanf("%d %d %d", &s, &e, &t);
            map[s][e] = -t;                // 設定負權邊代表 wormhole
        }

        // 使用 SPFA 檢測負環
        if (detectNegativeCycleUsingSPFA(1))
            printf("NO\n");                // 沒有負環
        else
            printf("YES\n");               // 存在負環
    }
    return 0;
}