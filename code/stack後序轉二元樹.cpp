#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int maxn = 11000;

struct node {
    int l, r;
    char c;
} e[maxn];

int cnt;
char s[maxn];

void initial() {
    int len = strlen(s);
    for (int i = 0; i <= len; i++) {
        e[i].l = e[i].r = -1;
    }
    cnt = 0;
}

void solve() {
    int len = strlen(s);
    stack<int> v;
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            e[cnt].c = s[i];
            v.push(cnt);
            cnt++;
        } else {
            int r = v.top();
            v.pop();
            int l = v.top();
            v.pop();
            e[cnt].l = l;
            e[cnt].r = r;
            e[cnt].c = s[i];
            v.push(cnt);
            cnt++;
        }
    }
}

void output() {
    string ans;
    queue<int> q;
    q.push(cnt - 1);
    while (!q.empty()) {
        int st = q.front();
        q.pop();
        ans.push_back(e[st].c);
        if (e[st].l != -1) q.push(e[st].l);
        if (e[st].r != -1) q.push(e[st].r);
    }
    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
}

int main() {
    while (scanf("%s", s) != EOF) {
        initial();
        solve();
        output();
    }
    return 0;
}
