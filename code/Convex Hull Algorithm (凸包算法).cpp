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
