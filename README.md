# codebook

\documentclass{article}
\usepackage{listings}  % 用來格式化顯示程式碼
\usepackage{xcolor}    % 用來自定義程式碼顏色
\usepackage{xeCJK}     % 支援中文
\usepackage{fancyhdr}  % 自定義頁眉頁腳
\usepackage{multicol}  % 用來分欄顯示
\usepackage{geometry}  % 調整頁邊距
\usepackage{titlesec}  % 控制標題格式

% 設置中文主字體
\setCJKmainfont{SimSun}

% 調整行距
\linespread{1.0}  % 保持正常行距

% 設置程式碼顯示樣式
\lstset{
  basicstyle=\ttfamily\small,               % 程式碼字體為 footnotesize
  keywordstyle=\bfseries\color{blue},              % 關鍵字樣式
  commentstyle=\itshape\scriptsize\color{green!50!black},  % 註解字體稍微縮小
  stringstyle=\color{red},                         % 字串顏色
  showstringspaces=false,                          % 不顯示空格
  numbers=left,                                    % 行號顯示在左邊
  numberstyle=\scriptsize\color{gray},             % 行號樣式
  stepnumber=1,                                    % 每行顯示行號
  numbersep=5pt,                                   % 行號與程式碼的間距
  breaklines=true,                                 % 開啟自動換行
  breakatwhitespace=true,                          % 在空白處換行
  tabsize=4,                                       % 設定 Tab 大小
  language=C++,                                    % 預設語言設為 C++
  columns=fullflexible                            % 減少字體間距，避免擠壓
}

% 設置頁邊距
\geometry{
  top=1in,
  bottom=1in,
  left=0.9in,    % 左邊邊距調整為 0.9in
  right=0.9in    % 右邊邊距調整為 0.9in
}

% 自定義頁眉和頁腳
\pagestyle{fancy}
\fancyhf{} % 清除預設頁眉頁腳
\fancyhead[L]{\fontsize{16}{18}\selectfont FJCU}  % 左側顯示學校名稱
\fancyhead[C]{\fontsize{16}{18}\selectfont Handmade}  % 調整頁眉中間的字體大小
\fancyhead[R]{\fontsize{16}{18}\thepage}  % 右上角顯示頁碼

% 調整標題格式，減少行與行之間的間距
\titleformat{\section}{\Large\bfseries}{}{0pt}{}
\titlespacing*{\section}{0pt}{10pt}{10pt}  % 控制 section 與上下內容的距離

% 設置分欄時的欄距和分隔線
\setlength{\columnsep}{35pt}  % 增大兩欄之間的欄距，設置為 35pt
\setlength{\columnseprule}{0.4pt}  % 設置兩欄之間的分隔線

\begin{document}


% 添加分欄，下面內容將分為兩欄顯示
\begin{multicols}{2}

\section{Vector}

\begin{lstlisting}[language=C++]
// vector 是 C++ 的動態陣列，可以根據需要自動調整大小。

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;  // 宣告一個整數型的 vector

    // 插入數據
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // 使用下標訪問數據
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";  // 輸出：10 20 30
    }
    cout << endl;

    // 使用迭代器遍歷數據
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";  // 輸出：10 20 30
    }
    cout << endl;

    return 0;
}
\end{lstlisting}

\section{使用 vector<vector<int>> 建立 2D 矩陣}

\begin{lstlisting}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 建立一個 3x3 的 2D 矩陣
    vector<vector<int>> matrix(3, vector<int>(3, 0));  // 初始值全為 0

    // 填充矩陣
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i + j;  // 例如矩陣元素等於 i+j
        }
    }

    // 輸出矩陣
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
\end{lstlisting}

\section{Map}

\begin{lstlisting}[language=C++]
// map 是 C++ STL 中的關聯式容器，提供鍵值對的存儲。

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;  // 宣告一個 map，key 為 string，value 為 int

    // 插入鍵值對
    m["apple"] = 5;
    m["banana"] = 10;
    m["orange"] = 7;

    // 使用 key 來訪問數據
    cout << "apple: " << m["apple"] << endl;  // 輸出：apple: 5

    // 遍歷 map
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second << endl;  // 輸出每個鍵值對
    }

    return 0;
}
\end{lstlisting}

\section{Stack}

\begin{lstlisting}[language=C++]
// stack 是後進先出的數據結構，適用於需要後進先出 (LIFO) 的場景。

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;  // 宣告一個整數型的 stack

    // 插入數據
    s.push(10);
    s.push(20);
    s.push(30);

    // 讀取並移除棧頂數據
    while (!s.empty()) {
        cout << "Top: " << s.top() << endl;  // 輸出當前棧頂數據
        s.pop();  // 移除棧頂數據
    }

    return 0;
}
\end{lstlisting}

\section{Priority Queue}

\begin{lstlisting}[language=C++]
// priority_queue 是一個優先隊列，預設情況下是大頂堆，根據優先級存儲數據。

#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;  // 宣告一個整數型的優先隊列，預設為大頂堆

    // 插入數據
    pq.push(30);
    pq.push(10);
    pq.push(20);

    // 讀取並移除隊列頂部數據
    while (!pq.empty()) {
        cout << "Top: " << pq.top() << endl;  // 輸出當前隊列頂部數據
        pq.pop();  // 移除頂部數據
    }

    return 0;
}
\end{lstlisting}

\section{Queue}

\begin{lstlisting}[language=C++]
// queue 是先進先出的數據結構，適用於需要先進先出 (FIFO) 的場景。

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;  // 宣告一個整數型的隊列

    // 插入數據
    q.push(10);
    q.push(20);
    q.push(30);

    // 讀取並移除隊首數據
    while (!q.empty()) {
        cout << "Front: " << q.front() << endl;  // 輸出當前隊首數據
        q.pop();  // 移除隊首數據
    }

    return 0;
}
\end{lstlisting}

\section{建樹}

\begin{lstlisting}[language=C++]
// 使用 DFS 方式建立樹結構

#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1005;  // 最大節點數
vector<int> tree[maxn];  // 用於存儲樹的鄰接表
bool visited[maxn];  // 記錄節點是否已被訪問

// 建立樹
void addEdge(int u, int v) {
    tree[u].push_back(v);
    tree[v].push_back(u);  // 因為是無向樹，雙向連接
}

// 深度優先搜索 (DFS) 建立樹
void dfs(int u) {
    visited[u] = true;
    for (int v : tree[u]) {
        if (!visited[v]) {
            cout << "Edge: " << u << " - " << v << endl;  // 輸出邊
            dfs(v);  // 繼續遞迴遍歷
        }
    }
}

int main() {
    int n = 5;  // 節點數

    // 建立樹的邊
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(2, 5);

    // 從節點1開始遍歷樹
    dfs(1);

    return 0;
}
\end{lstlisting}

\section{建圖}

\begin{lstlisting}[language=C++]
// 使用鄰接表建立圖

#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1005;  // 最大節點數
vector<pair<int, int>> graph[maxn];  // 用於存儲圖的鄰接表，pair 表示(鄰接點, 邊權重)

// 建立圖的邊 (有向圖)
void addEdge(int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));  // 添加一條從 u 到 v 的有向邊，邊的權重為 weight
}

int main() {
    int n = 5;  // 節點數

    // 建立圖的邊
    addEdge(1, 2, 10);  // 節點1到節點2，權重為10
    addEdge(1, 3, 5);
    addEdge(2, 4, 3);
    addEdge(3, 5, 2);

    // 輸出圖的鄰接表
    for (int u = 1; u <= n; u++) {
        cout << "Node " << u << " connects to: ";
        for (auto edge : graph[u]) {
            cout << "(" << edge.first << ", weight: " << edge.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
\end{lstlisting}


\section{Bit Index Tree (BIT) - Lowbit}

\begin{lstlisting}
// Bit Index Tree (BIT) - Lowbit
#define lowbit(x) ((x) & (-(x)))
int bit[2 * maxn] = {0};  // 宣告並初始化 bit 陣列

void add(int p, int v) {
    while (p < 2 * maxn) {
        bit[p] += v;    // 更新當前節點的值
        p += lowbit(p); // 跳到下一個需要更新的節點
    }
}

int sum(int p) {
    int ret = 0;
    while (p > 0) {
        ret += bit[p];  // 累加前綴和
        p -= lowbit(p); // 跳到上一個節點
    }
    return ret;
}
\end{lstlisting}

\section{Kruskal 最小生成樹 (MST)}

\begin{lstlisting}
// Kruskal MST (最小生成樹)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1005;  // 最大節點數

struct Point {
    int x, y;
};

struct Edge {
    int u, v;
    double cost;
    bool operator<(const Edge& e) const {
        return cost < e.cost;  // 按邊的權重排序
    }
};

int parent[maxn], rank[maxn];  // 並查集
Point points[maxn];  // 存儲每個點的座標
Edge e[maxn * maxn];  // 存儲所有邊
int m;  // 邊的數量

// 初始化並查集
void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// 路徑壓縮找根
int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

// 合併兩個集合
bool uni(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
        return true;
    }
    return false;
}

// 計算兩個點之間的歐幾里得距離
double dist(int u, int v) {
    int dx = points[u].x - points[v].x;
    int dy = points[u].y - points[v].y;
    return sqrt(dx * dx + dy * dy);
}

// Kruskal 最小生成樹算法
double kruskal(int n) {
    init(n);
    sort(e, e + m);  // 按權重對邊排序

    double ans = 0;
    int edge_count = 0;
    for (int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v;
        if (uni(u, v)) {  // 如果 u 和 v 不在同一集合中
            ans += e[i].cost;
            if (++edge_count == n - 1) break;  // 當邊數達到 n-1 時停止
        }
    }
    return ans;  // 返回最小生成樹的總權重
}

\end{lstlisting}

\section{SPFA 最短路徑算法}

\begin{lstlisting}
// SPFA 最短路徑算法
int dist[maxn];  // 存儲到達每個節點的最短距離
vector<pair<int, int>> E[maxn];  // 鄰接表存儲圖
bool vis[maxn];  // 訪問標記
int out[maxn];   // 用來檢測負環

bool spfa(int s, int n) {
    queue<int> Q;
    Q.push(s);  // 將起點s加入隊列
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = 0;
        out[u]++;
        if (out[u] > n) return false; // 出現負權重環
        for (int j = 0; j < E[u].size(); j++) {
            int v = E[u][j].first;
            if (dist[v] > dist[u] + E[u][j].second) {  // 有更短的路徑
                dist[v] = dist[u] + E[u][j].second;
                if (vis[v]) continue;
                vis[v] = 1;
                Q.push(v);  // 將v加入隊列
            }
        }
    }
    return true;
}
\end{lstlisting}

\section{連通集 (Disjoint Set)}

\begin{lstlisting}
// Disjoint Set 連通集 - 加權合併與路徑壓縮
int parent[maxn];
fill(parent, parent + maxn, -1);  // 初始化 parent 陣列，表示每個節點是獨立的

void weighted_union2(int i, int j) {
    int temp = parent[i] + parent[j];
    if (parent[i] > parent[j]) {
        parent[i] = j;  // j為新根
        parent[j] = temp;
    } else {
        parent[j] = i;  // i為新根
        parent[i] = temp;
    }
}

int find2(int i) {
    int root, trail, lead;
    for (root = i; parent[root] >= 0; root = parent[root]);  // 找根
    for (trail = i; trail != root; trail = lead) {           // 路徑壓縮
        lead = parent[trail];
        parent[trail] = root;
    }
    return root;
}
\end{lstlisting}

\section{Nim 遊戲 SG 函數}

\begin{lstlisting}
// Nim 遊戲 SG 函數
#define maxn 20+5
#define maxs 100+5
int sg[maxn];

void SG() {
    int mex[maxs] = {}; // MEX表初始化
    sg[0] = 0;          // 初始化SG值
    for (int i = 1; i < maxn; i++) {
        memset(mex, 0, sizeof(mex));  // 清空MEX數組
        for (int j = 0; j < i; j++) {
            mex[sg[j] ^ sg[i - j - 1]] = 1;  // Nim遊戲狀態轉移
        }
        int g = 0;
        while (mex[g]) g++;  // 找到最小的MEX
        sg[i] = g;  // 設置SG值
    }
}
\end{lstlisting}

\section{KM Algorithm 最大匹配問題}

\begin{lstlisting}
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
\end{lstlisting}

\section{Vector 建圖與多次 DFS 搜索}

\begin{lstlisting}
// Vector 建圖與多次 DFS 搜索
const int maxn = 1005;
vector<int> g[maxn], nodes[maxn];  // 建立鄰接表與節點集
int n, s, k, p[maxn];              // n為總節點數，s為起始節點，k為最大距離
bool c[maxn];                       // 節點是否被訪問過

void dfs1(int u, int f, int dist) {
    p[u] = f;  // 記錄父節點
    int nd = g[u].size();
    if (nd == 1 && dist > k) nodes[dist].push_back(u); // 遠距離節點加入
    for (int i = 0; i < nd; i++) {
        int v = g[u][i];
        if (v != f) dfs1(v, u, dist + 1);  // 遞迴進行DFS
    }
}

int solve() {
    int ans = 0;
    memset(c, false, sizeof(c));  // 初始化訪問數組
    for (int dist = (n - 1); dist > k; dist--) {
        for (int i = 0; i < nodes[dist].size(); i++) {
            int u = nodes[dist][i];
            if (c[u]) continue;
            int v = u;
            for (int j = 0; j < k; j++) v = p[v];
            dfs2(v, -1, 0);  // 執行DFS，標記被訪問過的節點
            ans++;
        }
    }
    return ans;
}

void dfs2(int u, int f, int d) {
    c[u] = true;  // 標記節點已訪問
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v != f && d < k) dfs2(v, u, d + 1);  // 深度優先搜索
    }
}
\end{lstlisting}

\section{Tree DP, DFS}

\begin{lstlisting}
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// 深度優先搜索進行動態規劃計算
void dfs(int u) {
    visited[u] = 1;  // 標記節點已訪問
    dp[u][0] = 0;  // 當前節點不選擇
    dp[u][1] = 1;  // 當前節點選擇

    // 遍歷所有相鄰節點
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (visited[v]) continue;
        dfs(v);  // 遞迴調用DFS
        dp[u][0] += dp[v][1];  // 當前節點不選擇時，子節點必須選擇
        dp[u][1] += min(dp[v][0], dp[v][1]);  // 當前節點選擇時，子節點可以選擇或不選擇
    }
}

int solve() {
    int ans = 0;
    memset(visited, 0, sizeof(visited));  // 初始化訪問數組
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs(i);  // 對每個未訪問的節點進行DFS
        ans += min(dp[i][0], dp[i][1]);  // 計算最小選擇
    }
    return ans;
}
\end{lstlisting}

\section{Dijkstra - 最短路徑算法}

\begin{lstlisting}
// Dijkstra 最短路徑算法
Dijkstra(G) {
   for each v in V {
      d[v] = infinity;  // 初始化所有點的距離
   }
   d[s] = 0;  // 起點距離為0
   S = {};  // 空集合S
   Q = V;   // 未處理的節點集合

   while (Q is not empty) {
      u = ExtractMin(Q);  // 選擇距離最小的節點u
      S = S U {u};        // 將u加入集合S
      for each v in u->Adj[] {
         if (d[v] > d[u] + w(u,v)) {
            d[v] = d[u] + w(u,v);  // 更新距離
         }
      }
   }
}
\end{lstlisting}

\section{Kruskal 最小生成樹 (MST, Disjoint Set Union)}

\begin{lstlisting}
// Kruskal 算法 - 最小生成樹
Kruskal() {
   T = {};  // 初始化空生成樹
   for each v in V {
      MakeSet(v);  // 初始化每個節點為單獨的集合
   }
   sort E by increasing edge weight w;  // 按邊權重排序
   for each (u,v) in E (in sorted order) {
      if FindSet(u) != FindSet(v) {
         T = T U {{u,v}};  // 將邊加入生成樹
         Union(FindSet(u), FindSet(v));  // 合併集合
      }
   }
}
\end{lstlisting}

\section{Priority Queue 操作}

\begin{lstlisting}
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
\end{lstlisting}

\section{高斯消去法 (Gaussian Elimination)}

\begin{lstlisting}
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
\end{lstlisting}

\section{排列組合與對數計算}

\begin{lstlisting}
// 使用對數進行排列組合的計算
#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    freopen("d:\\uva10883\\10883_in.txt", "r", stdin);
    freopen("d:\\uva10883\\10883_out.txt", "w", stdout);
    int Cas;
    scanf("%d", &Cas);
    for (int j = 1; j <= Cas; j++) {
        int N;
        double Res = 0, a, C = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%lf", &a);
            double sum = log2(fabs(a));
            if (i) {
                C += log2(double(N - i) / i);
                sum += C;
            }
            if (a < 0) {
                Res -= pow(2, sum - (N - 1));
            } else {
                Res += pow(2, sum - (N - 1));
            }
        }
        printf("Case #%d: %.3lf\n", j, Res);
    }
    return 0;
}
\end{lstlisting}

\section{過篩法與大數運算}

\begin{lstlisting}
// 使用過篩法進行質數篩選並處理大數運算
#include <iostream>
using namespace std;

const int maxn = 250000;
const int maxp = 22000 + 5;
int fp[maxp];
bool vis[maxn];

int main() {
    long long a = 0, b = 1, tmp;
    int n, count_p = 1;

    for (int i = 2; count_p < maxp; ++i) {
        tmp = a + b;
        a = b;
        b = tmp;

        if (b > 1e10) {
            b /= 10;
            a /= 10;
        }

        if (!vis[i]) {
            tmp = b;
            while (tmp >= 1e9) {
                tmp /= 10;
            }
            fp[count_p++] = tmp;
            for (int j = i * i; j < maxn; j += i) {
                vis[j] = true;
            }
        }
    }

    fp[1] = 2, fp[2] = 3;
    while (~scanf("%d", &n)) {
        printf("%d\n", fp[n]);
    }

    return 0;
}
\end{lstlisting}

\section{Python 過篩法與大數運算}

\begin{lstlisting}[language=Python]
maxn = 250000
maxp = 22000 + 5

# 初始化數組 fp 用來存儲質數的前幾位
fp = [0] * maxp
vis = [False] * maxn  # 記錄某數字是否被標記過

a, b = 0, 1  # 初始的 Fibonacci 數列
count_p = 1  # 質數計數器

i = 2
while count_p < maxp:
    tmp = a + b  # 計算 Fibonacci 序列
    a = b
    b = tmp
    if b > 1e10:  # 如果 b 太大，對其進行縮小處理
        b //= 10
        a //= 10

    if not vis[i]:  # 如果 i 沒有被標記為非質數
        tmp = b
        while tmp >= 1e9:  # 確保數字在合理範圍內
            tmp //= 10

        fp[count_p] = tmp  # 記錄第 count_p 個質數
        count_p += 1

        j = i * i
        while j < maxn:
            vis[j] = True  # 標記合數
            j += i

    i += 1

fp[1], fp[2] = 2, 3  # 手動設定前兩個質數

try:
    while True:
        n = int(input())  # 讀取輸入
        print(fp[n])  # 輸出第 n 個質數
except EOFError:
    pass  # 捕捉到 EOF 後退出循環
\end{lstlisting}

\section{Flow Algorithm (流量算法)}

\begin{lstlisting}[language=C++]
// 使用 Ford-Fulkerson 演算法來解最大流問題。
// 利用增廣路徑不斷增加流量，直到無法找到更多的增廣路徑。

#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

#define V 6  // 節點數，假設我們的圖有 6 個節點

// BFS 搜索增廣路徑，並填充 parent[] 用來存儲路徑
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V];  // 記錄哪些節點已經被訪問
    fill(visited, visited + V, false);  // 初始化所有節點為未訪問

    queue<int> q;  // 使用 BFS 搜索
    q.push(s);
    visited[s] = true;
    parent[s] = -1;  // 將源節點的父節點設為 -1 表示根節點

    // 進行標準的 BFS 搜索
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {  // 只考慮殘餘流量大於 0 的邊
                if (v == t) {  // 如果找到增廣路徑
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;  // 沒有找到增廣路徑
}

// Ford-Fulkerson 演算法的主函數，計算 s 到 t 的最大流
int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;
    int rGraph[V][V];  // 殘餘圖
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];  // 初始化殘餘圖

    int parent[V];  // 用來儲存 BFS 找到的路徑
    int max_flow = 0;  // 初始化最大流為 0

    // 不斷找增廣路徑，直到找不到為止
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;

        // 計算增廣路徑中的最小殘餘容量
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // 更新殘餘圖中的流量
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;  // 反向邊增加流量
        }

        max_flow += path_flow;  // 更新最大流
    }

    return max_flow;  // 返回最大流量
}
\end{lstlisting}

\section{Max Clique Algorithm (最大團算法)}

\begin{lstlisting}[language=C++]
// 最大團問題的求解：使用位元遮罩來計算最大團。
// 最大團指的是在無向圖中，一個最大完全子圖。

const int MAXN = 50;  // 節點數的最大限制
int n, adj[MAXN][MAXN];  // n 為節點數，adj 為鄰接矩陣
int maxCliqueSize = 0;  // 用來記錄找到的最大團的大小

// DFS 搜索來判斷最大團的大小
void dfs(int depth, int *now, int size) {
    if (depth == n) {  // 如果已經遍歷完所有節點
        maxCliqueSize = max(maxCliqueSize, size);  // 更新最大團大小
        return;
    }

    // 檢查當前節點 depth 是否可以加入到現有的團
    for (int i = 0; i < size; i++) {
        if (!adj[now[i]][depth]) return;  // 不是完全圖，返回
    }

    now[size] = depth;  // 將當前節點加入團
    dfs(depth + 1, now, size + 1);  // 繼續搜索加入當前節點的情況
    dfs(depth + 1, now, size);  // 搜索不加入當前節點的情況
}

// 主函數，計算最大團
int maxClique() {
    int now[MAXN];  // 用來存儲當前的團
    dfs(0, now, 0);  // 從第 0 層開始搜索
    return maxCliqueSize;  // 返回最大團的大小
}
\end{lstlisting}

\section{Miller-Rabin Primality Test (米勒-拉賓素性測試)}

\begin{lstlisting}[language=C++]
// 米勒-拉賓素數測試演算法：一種高效的隨機化素數判定方法。
// 利用快速冪與模數運算來測試一個數是否為素數。

typedef long long ll;

// 快速模數乘法，防止溢出
ll mulmod(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;  // 如果b的最低位為1，則加上a
        a = (a + a) % mod;  // a * 2
        b >>= 1;  // 右移 b
    }
    return res;
}

// 快速冪演算法，計算 base^exp % mod
ll powmod(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = mulmod(res, base, mod);  // 如果exp的最低位為1，乘上base
        base = mulmod(base, base, mod);  // base * base
        exp >>= 1;  // 右移 exp
    }
    return res;
}

// 米勒-拉賓測試演算法
bool miller_rabin(ll n, int k) {
    if (n < 2) return false;  // 如果 n < 2 不是素數
    if (n != 2 && n % 2 == 0) return false;  // 偶數不是素數

    ll d = n - 1;
    while (d % 2 == 0) d /= 2;  // 分解 d 使得 n-1 = d * 2^r

    // 重複測試 k 次
    while (k--) {
        ll a = 2 + rand() % (n - 3);  // 隨機選擇一個測試基數 a
        ll x = powmod(a, d, n);  // 計算 a^d % n

        if (x == 1 || x == n - 1) continue;  // 可能是素數

        while (d != n - 1) {
            x = mulmod(x, x, n);  // 平方，計算 x^2 % n
            d *= 2;

            if (x == 1) return false;  // 合數
            if (x == n - 1) break;  // 可能是素數
        }

        if (x != n - 1) return false;  // 如果 x 最終不等於 n-1 則為合數
    }

    return true;  // 通過所有測試，n 可能是素數
}
\end{lstlisting}

\section{Convex Hull Algorithm (凸包算法)}

\begin{lstlisting}[language=C++]
// 凸包演算法：使用 Andrew's monotone chain 演算法來計算一組點的凸包。
// 凸包是能包圍所有點的最小凸多邊形。

#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;  // 定義一個點 (x, y)
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);  // 按照 x 進行排序，若 x 相同則按 y 排序
    }
};

// 計算向量 OA 和 OB 的叉積，用來判斷轉向
int cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// 計算一組點的凸包，返回凸包的點集
vector<Point> convex_hull(vector<Point>& P) {
    int n = P.size(), k = 0;
    vector<Point> H(2 * n);  // 最多有 2*n 個點

    sort(P.begin(), P.end());  // 將點按照 x 坐標排序

    // 構建下半凸包
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;  // 移除不滿足條件的點
        H[k++] = P[i];  // 將當前點加入到凸包
    }

    // 構建上半凸包
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;  // 移除不滿足條件的點
        H[k++] = P[i];  // 將當前點加入到凸包
    }

    H.resize(k - 1);  // 刪除最後一個重複點
    return H;  // 返回凸包的點集
}
\end{lstlisting}


\end{multicols}

\end{document}
