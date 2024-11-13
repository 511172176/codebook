//POJ2001
/*
v.push_back(10) 將元素添加到 vector 的尾部。
v.pop_back() 移除 vector 尾部的元素。
v.size() 返回當前 vector 中元素的個數。
v.empty() 檢查 vector 是否為空。
v.clear() 移除 vector 中的所有元素，使其變為空。
v.resize(5) 調整 vector 的大小，可以擴展或縮減 vector 的長度。
v.at(2) 返回指定索引位置的元素，並進行越界檢查。
v[2] 返回指定索引位置的元素，不進行越界檢查。
v.front() 返回 vector 首元素的引用。
v.back() 返回 vector 尾元素的引用。
v.insert(v.begin() + 2, 10) 在指定位置插入元素，位置之前的元素會向後移動。
v.erase(v.begin() + 2) 移除指定位置或區域的元素，之後的元素會向前移動。
v.capacity() 返回 vector 的容量，即不需要重新分配的情況下可容納的最大元素數量。
v.reserve() 預留空間以增加容量，避免頻繁擴展。
v.shrink_to_fit() 將容量縮減到等於當前元素數量，以釋放多餘的空間。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1000 + 10;       // 單詞的最大長度
const int maxnode = 100005;       // Trie 樹的最大節點數量
const int sigma_size = 26;        // 字母表的大小（假設只有小寫字母）
char str[MAXN][25];               // 儲存單詞的陣列
int ch[maxnode][sigma_size];      // Trie 樹的子節點指標
int val[maxnode];                 // Trie 樹節點的取值次數

int sz = 1;                       // Trie 樹的節點數量，初始化為 1（包含根節點）

// 初始化 Trie 樹
void initializeTrie() {
    sz = 1;                        // 重置節點數量
    memset(ch[0], 0, sizeof(ch[0]));  // 初始化根節點
}

// 將字母轉換成數字索引
int charToIndex(char c) {
    return c - 'a';                 // 將字符轉換為 0-25 的索引
}

// 插入單詞到 Trie 樹中
void insert(char *s) {
    int u = 0;                      // 起始於根節點 u = 0
    int n = strlen(s);               // 獲取單詞的長度
    for (int i = 0; i < n; i++) {
        int c = charToIndex(s[i]);   // 計算字母的索引值
        if (!ch[u][c]) {             // 若該節點不存在，則創建新節點
            memset(ch[sz], 0, sizeof(ch[sz]));  // 初始化新節點
            ch[u][c] = sz++;         // 設置子節點並增加節點數量
        }
        u = ch[u][c];                // 移動到下一個節點
        val[u]++;                    // 計算到達該節點的次數
    }
}

// 查詢單詞在 Trie 中的最短唯一前綴
void query(char *s) {
    int u = 0;                       // 起始於根節點 u = 0
    int n = strlen(s);               // 獲取單詞的長度
    for (int i = 0; i < n; i++) {
        putchar(s[i]);               // 輸出當前字母
        int c = charToIndex(s[i]);   // 計算字母的索引值
        if (val[ch[u][c]] == 1) return;  // 若當前子節點的次數為 1，則找到最短前綴
        u = ch[u][c];                // 移動到下一個節點
    }
}

int main() {
    int tot = 0;                     // 單詞數初始化
    initializeTrie();                // 初始化 Trie 樹

    // 讀取每個單詞並插入到 Trie
    while (scanf("%s", str[tot]) != EOF) {
        insert(str[tot]);            // 插入單詞到 Trie
        tot++;                       // 單詞數累加
    }

    // 查詢每個單詞的最短唯一前綴
    for (int i = 0; i < tot; i++) {
        printf("%s ", str[i]);       // 輸出單詞
        query(str[i]);               // 查詢單詞的最短前綴
        printf("\n");                // 換行
    }

    return 0;
}
