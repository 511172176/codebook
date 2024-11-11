//POJ3437
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;                       // 輸入的字符串
int i, n = 0, height1, height2; // 迭代變量 i, 樹的編號 n, 兩種高度變量

// 遞迴構建二元樹並計算高度
void calculateHeights(int level1, int level2) {
    int tempson = 0;              // 當前節點的子節點數量
    while (s[i] == 'd') {         // 如果當前字元是 'd'（代表向下擴展）
        i++;                      // 移動到下一個字元
        tempson++;                // 計算子節點
        calculateHeights(level1 + 1, level2 + tempson); // 遞迴進入下一層
    }
    height1 = max(height1, level1);   // 更新高度1（基於深度）
    height2 = max(height2, level2);   // 更新高度2（基於水平位置）
    if (s[i] == 'u') i++;             // 若為 'u' 字元，則返回到父節點
}

// 初始化並輸出結果
void processTree() {
    i = height1 = height2 = 0;    // 重置索引和高度
    calculateHeights(0, 0);       // 計算樹的高度
    cout << "Tree " << ++n << ": " << height1 << " => " << height2 << endl;
}

int main() {
    while (cin >> s && s != "#") {
        processTree(); // 對每棵樹進行處理
    }
    return 0;
}


