// 優先隊列的操作與應用
#include <cstdio>
#include <queue>
using namespace std;

class Item {
public:
    int Q_num, Period, Time;
    bool operator < (const Item& a) const {
        return (Time > a.Time || (Time == a.Time && Q_num > a.Q_num));
    }
};

int main() {
    priority_queue<Item> pq;
    char s[20];
    while (scanf("%s", s) && s[0] != '#') {
        Item item;
        scanf("%d%d", &item.Q_num, &item.Period);
        item.Time = item.Period;
        pq.push(item);
    }
    int K;
    scanf("%d", &K);
    while (K--) {
        Item r = pq.top();
        pq.pop();
        printf("%d\n", r.Q_num);
        r.Time += r.Period;
        pq.push(r);
    }
}
\end{lstlisting}

\section{二分搜索算法}

\begin{lstlisting}
// 二分搜索算法與貪心飛機降落時間
int I, n, caseNo = 1, order[8];
double a[8], b[8], L, maxL;

double greedyLanding() {
    double lastLanding = a[order[0]];  // 第一架飛機的降落時間
    for (int i = 1; i < n; i++) {
        double target = lastLanding + L;
        if (target <= b[order[i]]) {  // 下一架飛機可以按計畫降落
            lastLanding = max(a[order[i]], target);  // 更新降落時間
        } else {
            return 1;  // 無法完成
        }
    }
    return lastLanding - b[order[n - 1]];  // 返回結果
}
\end{lstlisting}

\section{Priority Queue 合併操作}

\begin{lstlisting}
// 使用優先隊列合併兩個數組
class Item {
public:
    int Q_num, Period, Time;
    Item(int q, int p, int t) : Q_num(q), Period(p), Time(t) {}  // 構造函數
    bool operator<(const Item& a) const {
        return (Time > a.Time || (Time == a.Time && Q_num > a.Q_num));
    }
};

void merge(int* A, int* B, int* C, int k) {
    priority_queue<Item> q;
    for (int i = 0; i < k; i++) {
        q.push(Item(A[i] + B[0], 0));
    }
    for (int i = 0; i < k; i++) {
        Item item = q.top(); q.pop();
        C[i] = item.sum;  // 保存當前的最小值
        int b = item.b;
        if (b + 1 < k) {
            q.push(Item(item.sum - B[b] + B[b + 1], b + 1));  // 更新優先隊列
        }
    }
}
