// stack 是後進先出的數據結構，適用於需要後進先出 (LIFO) 的場景。

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;  // 宣告一個整數型的 stack

    // 插入數據
    s.push(10);
    s.push(20);
    s.push(30);

    // 讀取並移除棧頂數據
    while (!s.empty()) {
        cout << "Top: " << s.top() << endl;  // 輸出當前棧頂數據
        s.pop();  // 移除棧頂數據
    }

    return 0;
}
