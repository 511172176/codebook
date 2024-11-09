#include <iostream>
#include <vector>
using namespace std;

vector<int> Fa;

int Get_father(int x) {
    return Fa[x] == x ? x : Fa[x] = Get_father(Fa[x]);
}

int main() {
    int N, M;
    while (cin >> N) {  // read N (number of nodes)
        vector<vector<int>> P(N + 1, vector<int>(N + 1, 0));
        Fa.resize(N + 1);

        for (int i = 0; i < N; i++) {  // input adjacency matrix
            for (int j = 0; j < N; j++) {
                cin >> P[i][j];
            }
        }

        for (int i = 0; i <= N; i++) Fa[i] = i;

        cin >> M;
        while (M--) {  // process M edges
            int a, b;
            cin >> a >> b;
            Fa[Get_father(a - 1)] = Get_father(b - 1);
        }

        int ans = 0;
        for (int k = 1; k <= 1000; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (P[i][j] == k && Get_father(i) != Get_father(j)) {
                        Fa[Get_father(i)] = Get_father(j);
                        ans += k;
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
