//ZOJ2724
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 60000 + 10;
const int maxs = 100;

// 定義結構體來存儲佇列的資訊
struct Info {
    char name[maxs]; // 名稱
    int para;        // 儲存的參數
    int pri;         // 優先級
    int t;           // 插入時間，用於維持先插入先處理
};

Info p[maxn];       // 儲存所有的 Info 物件
int used = 0;       // `p` 的下一個可用索引
int cnt = 0;        // 記錄插入的順序，維持穩定性

// 自定義比較器，用於在優先佇列中排序
struct Compare {
    bool operator()(const int a, const int b) const {
        if (p[a].pri != p[b].pri)         // 若優先級不同，根據優先級排序
            return p[a].pri > p[b].pri;   // 優先級越小優先處理
        return p[a].t > p[b].t;           // 若優先級相同，插入時間早者優先
    }
};

// 定義優先佇列
priority_queue<int, vector<int>, Compare> pq;

// 處理 GET 命令，從優先佇列取出元素
void processGetCommand() {
    if (!pq.empty()) {
        int top_idx = pq.top();      // 獲取最高優先級的元素索引
        pq.pop();                    // 從佇列中刪除該元素
        printf("%s %d\n", p[top_idx].name, p[top_idx].para); // 輸出元素資訊
    } else {
        printf("EMPTY QUEUE!\n");    // 若佇列為空，輸出 "EMPTY QUEUE!"
    }
}

// 處理 PUT 命令，將新元素插入優先佇列
void processPutCommand() {
    // 讀取並存儲新元素的 name、para、pri 資訊
    scanf("%s %d %d", p[used].name, &p[used].para, &p[used].pri);
    p[used].t = cnt++;               // 設置插入順序並遞增
    pq.push(used++);                 // 將新元素的索引壓入優先佇列
}

// 主函式，處理輸入並根據指令執行相應操作
void processCommands() {
    char command[maxs];              // 儲存命令名稱

    // 循環讀取命令，直到文件結尾
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "GET") == 0) {
            processGetCommand();     // 處理 GET 命令
        } else {                     // 否則視為 PUT 命令
            processPutCommand();     // 處理 PUT 命令
        }
    }
}

int main() {
    processCommands();               // 處理所有輸入命令
    return 0;
}

