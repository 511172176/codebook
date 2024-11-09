#include <iostream>
#include <ext/rope>  // 使用 GNU C++ rope 函式庫
using namespace std;
using namespace __gnu_cxx;  // rope 所在的命名空間

/*
  rope 函式庫提供的基本操作有：
  list.insert(p, str);      // 將字串 str 插入到 rope 的 p 位置
  list.erase(p, c);         // 刪除 rope 中從 p 位置開始的 c 個字元
  list.substr(p, c);        // 擷取 rope 中從 p 位置開始長度為 c 的子字串
  list.copy(q, p, c);       // 將 rope 中從 p 位置開始長度為 c 的子字串複製到 q
*/

using namespace std;

rope<char> ro, tmp;               // 定義 rope 物件
rope<char> l[50005];        // 紀錄每個版本

char str[205];               // 用於暫存輸入的字串

int main() {
    int n, op, p, c, d, v, cnt;
    cin >> n;
    d = 0;
    cnt = 1;
    while (n--) {
        cin >> op;

        if (op == 1) {  // 插入命令
            cin >> p >> str;
            p -= d;                   // 計算相對位置
            ro.insert(p, str);         // 將字串 str 插入 rope 的 p 位置
            l[cnt++] = ro;             // 將版本 ro 儲存到 l[cnt]，版本計數 + 1
        } else if (op == 2) {  // 刪除命令
            cin >> p >> c;
            p -= d; c -= d;          // 計算相對位置和長度
            ro.erase(p-1, c);            // 刪除 rope 中從 p 位置開始的 c 個字元

            l[cnt++] = ro;             // 將版本 ro 儲存到 l[cnt]，版本計數 + 1
        } else {  // 列印命令
            cin >> v >> p >> c;

            p -= d; v -= d; c -= d;   // 計算相對位置和長度
            tmp = l[v].substr(p-1, c);  // 擷取版本 v 中從 p 位置開始長度為 c 的子字串
            d += count(tmp.begin(), tmp.end(), 'c');  // 計算子字串 tmp 中 'c' 的出現次數
            cout << tmp << "\n";       // 輸出子字串 tmp
        }
    }

    return 0;
}

/*
6
1 0 abcdefgh
2 4 3
3 1 2 5
*/
