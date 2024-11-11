//POJ3367
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 11000;

struct node {
    int l, r;  // 左右子節點的索引
    char c;    // 節點的字元值
} e[maxn];

int cnt;       // 節點數量
char s[maxn];  // 存儲輸入的後序表達式

// 初始化二元樹節點結構
void initial() {
    int len = strlen(s);
    for (int i = 0; i <= len; i++) {
        e[i].l = e[i].r = -1;  // 初始化左右子節點為 -1，表示無子節點
    }
    cnt = 0;  // 重置節點計數器
}

// 將後序表達式轉換為二元樹
void solve() {
    int len = strlen(s);
    stack<int> v;  // 用來處理二元樹節點的堆疊
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {  // 若為字母節點
            e[cnt].c = s[i];  // 將字母存入節點
            v.push(cnt);      // 將當前節點索引壓入堆疊
            cnt++;            // 節點數加一
        } else {  // 若為操作符節點
            int r = v.top();  // 彈出右子節點
            v.pop();
            int l = v.top();  // 彈出左子節點
            v.pop();
            e[cnt].l = l;     // 設置當前節點的左子節點
            e[cnt].r = r;     // 設置當前節點的右子節點
            e[cnt].c = s[i];  // 將操作符存入節點
            v.push(cnt);      // 將當前節點索引壓入堆疊
            cnt++;            // 節點數加一
        }
    }
}

// 層次遍歷輸出並反轉結果
void output() {
    string ans;
    queue<int> q;
    q.push(cnt - 1);  // 將根節點（最後一個節點）加入隊列
    while (!q.empty()) {
        int st = q.front();
        q.pop();
        ans.push_back(e[st].c);  // 將節點的字元加入結果字串
        if (e[st].l != -1) q.push(e[st].l);  // 若有左子節點，則加入隊列
        if (e[st].r != -1) q.push(e[st].r);  // 若有右子節點，則加入隊列
    }
    reverse(ans.begin(), ans.end());  // 反轉結果，取得所需順序
    printf("%s\n", ans.c_str());      // 輸出結果
}

int main() {
    int t;
    scanf("%d", &t);  // 測試案例數
    while (t--) {
        scanf("%s", s);  // 讀取後序表達式
        initial();       // 初始化樹節點
        solve();         // 將後序表達式轉換為二元樹
        output();        // 輸出結果
    }
    return 0;
}
