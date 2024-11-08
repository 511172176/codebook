#include<iostream>
#include<vector>
#include<cstring>
const int maxn = 100000+5;
int n, m;
int set[maxn + maxn];
int set_find(int d)
{

    if(set[d] < 0)
        return d;
    return set[d] = set_find(set[d]);
}
int main(void)
{

    int loop;
    scanf("%d", &loop);
    while(loop--)
    {
        scanf("%d%d", &n, &m);
        memset(set, -1, sizeof(set));
        for(int i=0; i<m; i++)
        {
            int a, b;
            char s[5];
            scanf("%s%d%d", s, &a, &b);
            if(s[0] == 'A')
            {
                if(set_find(a) != set_find(b) && set_find(a) != set_find(b+n))
                    printf("%s\n", "Not sure yet.");
                else if(set_find(a) == set_find(b))
                    printf("%s\n", "In the same gang.");
                else
                    printf("%s\n", "In different gangs.");
            }
            else
            {
                if(set_find(a) != set_find(b+n))
                {
                    set[set_find(a)] = set_find(b+n);
                    set[set_find(b)] = set_find(a+n);
                }
            }
        }
    }
    return 0;
}
