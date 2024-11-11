#include <bits/stdc++.h>
using namespace std;
const int V = 55;
const int INF = 0x3f3f3f3f;
const int N = 15, M = 30;

int cap[V][V];
int flow[V][V];
int parent[V];
int num[N][M];
int S, T;
int maxflow;

void init()
{
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    memset(num, 0, sizeof(num));
}
bool find_path()
{
    bool vis[V] = {};
    queue<int> Q;
    Q.push(S);
    vis[S] = true;
    parent[S] = S;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int v=1; v<=T; v++)
        {
            if(!vis[v] && cap[u][v] - flow[u][v] > 0)
            {
                vis[v] = true;
                parent[v] = u;
                Q.push(v);
            }
        }
        if(vis[T]) return true;
    }
    return false;
}

void do_flow()
{
    int f = 10000000;
    int now;

    for(now = T; now!=S; now = parent[now])
    {
        f = min(f, cap[parent[now]][now] - flow[parent[now]][now]);
    }

    for(now = T; now != S; now = parent[now])
    {
        flow[parent[now]][now] += f;
        flow[now][parent[now]] += f;
    }
    maxflow += f;
}

int main()
{
    int test, Case=0;
    int n, m, k;
    int person, sticker;

    cin >> test;
    while(test--)
    {
        init();
        cin >> n >> m;

        S = 1, T = n+m+1;

        for(person = 1; person <= n; person++)
        {
            cin >> k;
            while(k--)
            {
                cin >> sticker;
                num[person][sticker]++;
            }
        }

        for(sticker = 1; sticker <= m; sticker++)
        {
            if(num[S][sticker] > 0)
            {
                cap[S][n+sticker] = num[S][sticker];
            }
            cap[n+sticker][T] = 1;
        }

        for(person = 2; person <=n; person++)
        {
            for(sticker = 1; sticker<=m ;sticker++)
            {
                if(num[person][sticker] == 0)
                    cap[n+sticker][person] = 1;
                if(num[person][sticker] > 1)
                    cap[person][n+sticker] = num[person][sticker] -1;
            }
        }
        maxflow = 0;
        while(find_path())
        {
            do_flow();
        }
        cout << "Case #" << ++Case << ": " << maxflow << "\n";
    }
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int to, cap, rev;
};

const int MAXV = 55;
const int INF = 0x3f3f3f3f;

vector<edge> G[MAXV];
int iter[MAXV], level_arr[MAXV];

// 添加邊到流網絡中，包含反向邊
void add_edge(int from, int to, int cap)
{
    G[from].push_back(edge{to, cap, (int)G[to].size()});
    G[to].push_back(edge{from, 0, (int)G[from].size() - 1});
}

// BFS 用於建立層級圖
void bfs(int s)
{
    fill(level_arr, level_arr + MAXV, -1);
    queue<int> q;
    level_arr[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto &e : G[v])
        {
            if(e.cap > 0 && level_arr[e.to] == -1)
            {
                level_arr[e.to] = level_arr[v] + 1;
                q.push(e.to);
            }
        }
    }
}

// DFS 用於尋找增廣路徑
int dfs(int v, int t, int upTo)
{
    if(v == t)
        return upTo;
    for(int &i = iter[v]; i < G[v].size(); ++i)
    {
        edge &e = G[v][i];
        if(e.cap > 0 && level_arr[e.to] > level_arr[v])
        {
            int d = dfs(e.to, t, min(upTo, e.cap));
            if(d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// 計算最大流
int max_flow(int s, int t)
{
    int flow = 0;
    while(1)
    {
        bfs(s);
        if(level_arr[t] == -1)
            break;
        fill(iter, iter + MAXV, 0);
        while(1)
        {
            int f = dfs(s, t, INF);
            if(f == 0)
                break;
            flow += f;
        }
    }
    return flow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int tt = 1; tt <= T; ++tt)
    {
        int N, M;
        cin >> N >> M;
        int C[15][30];
        memset(C, 0, sizeof(C));

        // 讀取每個節點的連接情況
        for(int i = 0; i < N; ++i)
        {
            int k;
            cin >> k;
            for(int j = 0; j < k; ++j)
            {
                int ki;
                cin >> ki;
                --ki; // 轉為 0-based 索引
                C[i][ki]++;
            }
        }

        // 設置源點和匯點
        int s = N + M;
        int t = s + 1;
        int V = t + 1;

        // 清空之前的流網絡
        for(int v = 0; v < V; ++v)
            G[v].clear();

        // 添加源點到機器人的邊
        for(int j = 0; j < M; j++)
            if(C[0][j] > 0)
                add_edge(s, N + j, C[0][j]);

        // 添加機器人到匯點的邊
        for(int i = 0; i < M; i++)
            add_edge(N + i, t, 1);

        // 添加任務到匯點或其他機器人的邊
        for(int i = 1; i < N; i++)
            for(int j = 0; j < M; j++)
            {
                if(C[i][j] == 0)
                    add_edge(N + j, i, 1);
                else if(C[i][j] > 1)
                    add_edge(i, N + j, C[i][j] - 1);
            }

        // 計算最大流
        int flow = max_flow(s, t);

        // 輸出結果
        cout << "Case #" << tt << ": " << flow << '\n';
    }
    return 0;
}
*/
/*
範例輸入:
2
2 5
6 1 1 1 1 1 1
3 1 2 2
3 5
4 1 2 1 1
3 2 2 2
5 1 3 4 4 3

預期輸出:
Case #1: 0
Case #2: 0
*/
