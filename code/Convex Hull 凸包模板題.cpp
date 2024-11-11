//UVA11626
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-10;
const int maxn = 100000 + 10;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    // 判斷兩點是否相等
    bool operator==(const Point &rhs) const {
        return fabs(x - rhs.x) < eps && fabs(y - rhs.y) < eps;
    }

    // 比較兩點的大小，先比較 x 再比較 y
    bool operator<(const Point &rhs) const {
        return x < rhs.x || (fabs(x - rhs.x) < eps && y < rhs.y);
    }
};

typedef Point Vector;

// 向量相減
Vector operator-(Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}

// 計算向量叉積，若結果為正表示逆時針，負為順時針，0 表示共線
double Cross(Vector A, Vector B) {
    return A.x * B.y - A.y * B.x;
}

// 使用 Andrew's Monotone Chain 算法計算凸包
int convexHull(Point *p, int n, Point *ch) {
    // 排序點集，並去除重複點
    sort(p, p + n);
    n = unique(p, p + n) - p;

    int m = 0; // 凸包頂點數

    // 構建下半部分凸包
    for (int i = 0; i < n; i++) {
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0) m--;
        ch[m++] = p[i];
    }

    int k = m; // 下半部分結束的位置

    // 構建上半部分凸包
    for (int i = n - 2; i >= 0; i--) {
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0) m--;
        ch[m++] = p[i];
    }

    // 若點數大於 1，則去除最後一個重複的點
    if (n > 1) m--;

    return m; // 返回凸包頂點數
}

int main() {
    int T;
    scanf("%d", &T); // 讀取測試案例數量
    while (T--) {
        int n;
        scanf("%d", &n); // 讀取點數
        Point p[maxn], ch[maxn]; // 點集和凸包頂點集

        // 讀取每個點的坐標
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf %*c", &p[i].x, &p[i].y);
        }

        // 計算凸包
        int m = convexHull(p, n, ch);

        // 輸出凸包頂點數
        printf("%d\n", m);

        // 輸出凸包頂點
        for (int i = 0; i < m; i++) {
            printf("%.0lf %.0lf\n", ch[i].x, ch[i].y);
        }
    }
    return 0;
}