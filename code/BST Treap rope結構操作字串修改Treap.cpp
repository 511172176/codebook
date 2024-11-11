//UVA12538
/*
  rope 函式庫提供的基本操作有：
  list.insert(p, str);      // 將字串 str 插入到 rope 的 p 位置
  list.erase(p, c);         // 刪除 rope 中從 p 位置開始的 c 個字元
  list.substr(p, c);        // 擷取 rope 中從 p 位置開始長度為 c 的子字串
  list.copy(q, p, c);       // 將 rope 中從 p 位置開始長度為 c 的子字串複製到 q
*/
#include <iostream>
#include <ext/rope>  // 使用 GNU C++ rope 函式庫
using namespace std;
using namespace __gnu_cxx;  // rope 所在的命名空間

rope<char> ro;            // 定義當前版本的 rope 物件
rope<char> l[50005];      // 紀錄每個版本
char str[205];            // 用於暫存輸入的字串
int cnt = 1, d = 0;       // 版本計數器和偏移值

// 插入操作：將字串插入 rope 的指定位置
void insertString(int p, const char* str) {
    p -= d;               // 計算相對位置
    ro.insert(p, str);    // 將字串 str 插入 rope 的 p 位置
    l[cnt++] = ro;        // 儲存當前版本
}

// 刪除操作：刪除 rope 中指定位置的指定長度的字元
void deleteString(int p, int c) {
    p -= d; c -= d;       // 計算相對位置和長度
    ro.erase(p - 1, c);   // 刪除 rope 中從 p 開始長度為 c 的字元
    l[cnt++] = ro;        // 儲存當前版本
}

// 列印操作：從指定版本擷取子字串並輸出，並計算 'c' 的次數
void printSubstring(int v, int p, int c) {
    p -= d; v -= d; c -= d;  // 計算相對位置和長度
    rope<char> tmp = l[v].substr(p - 1, c);  // 擷取指定版本的子字串
    d += count(tmp.begin(), tmp.end(), 'c'); // 計算子字串中 'c' 的出現次數並更新偏移
    cout << tmp << "\n";    // 輸出子字串
}

// 主函式，處理所有命令
void processCommands() {
    int n, op, p, c, v;
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == 1) {          // 插入命令
            cin >> p >> str;
            insertString(p, str); // 呼叫插入操作
        } else if (op == 2) {   // 刪除命令
            cin >> p >> c;
            deleteString(p, c);   // 呼叫刪除操作
        } else if (op == 3) {   // 列印命令
            cin >> v >> p >> c;
            printSubstring(v, p, c); // 呼叫列印操作
        }
    }
}

int main() {
    processCommands();
    return 0;
}
