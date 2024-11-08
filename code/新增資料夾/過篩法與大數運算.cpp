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
