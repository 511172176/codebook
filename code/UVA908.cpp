#include <bits/stdc++.h>
#define Max 1000005
using namespace std;

struct Edge
{
    int u, v, w;
}g[Max];
int fa[Max], n, m, ans;
int a, b, c, cnt, k, cacnt;

void add(int u, int v, int w)
{
    g[++cnt].u = u;
    g[cnt].v = v;
    g[cnt].w = w;
}
bool cmp(Edge x, Edge y)
{
    return x.w<y.w;
}

int find(int x)
{
    if(x!=fa[x])
        return fa[x]=find(fa[x]);
    return x;
}

void kruskal()
{
    sort(g+1, g+m+1, cmp);

    for(int i=1; i<=m; i++)
    {
        int u = find(g[i].u);
        int v = find(g[i].v);

        if(u==v) continue;
        ans+=g[i].w;
        fa[v]=u;
        cnt++;
    }
}

int main()
{
    while(~scanf("%d", &n) && n)
    {
        cnt = 0;
        if(cacnt!=0) puts("");
        cacnt++;

        for(int i=1; i<=n-1; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            ans +=c;
        }
        printf("%d\n", ans);
        ans = 0;

        scanf("%d", &k);
        for(int i=1; i<=k; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        scanf("%d", &m);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        m+=k;
        for(int i=1; i<=m; i++)
            fa[i] = i;

        kruskal();
        printf("%d\n", ans);
        ans=0;
    }


    return 0;
}

/*
5
1 2 5
1 3 5
1 4 5
1 5 5
1
2 3 2
6
1 2 5
1 3 5
1 4 5
1 5 5
3 4 8
4 5 8
*/
