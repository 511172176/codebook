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
