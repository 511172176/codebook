// vector 是 C++ 的動態陣列，可以根據需要自動調整大小。

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;  // 宣告一個整數型的 vector

    // 插入數據
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // 使用下標訪問數據
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";  // 輸出：10 20 30
    }
    cout << endl;

    // 使用迭代器遍歷數據
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";  // 輸出：10 20 30
    }
    cout << endl;

    return 0;
}
\end{lstlisting}

\section{使用 vector<vector<int>> 建立 2D 矩陣}

\begin{lstlisting}
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
