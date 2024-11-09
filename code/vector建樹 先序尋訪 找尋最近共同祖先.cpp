//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 10000;
vector<int> a[N];
int f[N], r[N];
void DFS(int u, int dep)
{
    r[u] = dep;
    for(vector<int>::iterator it = a[u].begin(); it != a[u].end(); it++)
        DFS(*it, dep + 1);
}
int main()
{

    int casenum, num, n, i, x, y;
    scanf("%d", &casenum);
    for(num=0; num<casenum; num++)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++) a[i].clear();
        memset(f, 255, sizeof(f));
        for(i=0; i<n-1; i++)
        {
            scanf("%d %d", &x, &y);
            a[x-1].push_back(y-1);
            f[y-1] = x-1;
        }
        for(i=0; f[i]>=0; i++);
        DFS(i, 0);
        scanf("%d %d", &x, &y);
        x--; y--;
        while(x != y)
        {
            if(r[x] > r[y]) x = f[x];
            else y = f[y];
        }
        printf("%d\n", x+1);
    }
    return 0;
}
