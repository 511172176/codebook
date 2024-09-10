#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 建立一個 3x3 的 2D 矩陣
    vector<vector<int>> matrix(3, vector<int>(3, 0));  // 初始值全為 0

    // 填充矩陣
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i + j;  // 例如矩陣元素等於 i+j
        }
    }

    // 輸出矩陣
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
