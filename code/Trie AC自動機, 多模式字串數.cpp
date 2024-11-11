//HDOJ2222
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int MAXN = 1e6 + 6;    // 最大字串大小，根據需要調整
int cnt;                     // 匹配模式字串的次數計數器

// Trie 節點結構定義
struct node {
    int sum;                 // 該節點的匹配次數
    node *next[26];          // 子節點的指標陣列（對應 a-z）
    node *fail;              // 失敗指針

    node() : sum(0), fail(nullptr) {
        for(int i = 0; i < 26; i++) next[i] = nullptr;
    }
};
node *root;                  // Trie 樹的根節點
char key[70];                // 用於儲存模式字串
char pattern[MAXN];          // 用於儲存目標字串
int N;                       // 模式字串數量

// 初始化 Trie 樹，建立根節點
void initializeTrie() {
    root = new node(); // 建立根節點
}

// 將單個模式字串插入到 Trie 樹中
void insertToTrie(char *s)
{
    node *p = root; // 從 Trie 樹的根節點開始
    for (int i = 0; s[i]; i++) {
        int x = s[i] - 'a';  // 計算字母的索引值（0 到 25）
        if (p->next[x] == nullptr) {
            p->next[x] = new node(); // 若該子節點不存在，則創建新節點
        }
        p = p->next[x];        // 移動到下一個節點
    }
    p->sum++; // 該節點的匹配次數加 1
}

// 建立 AC 自動機的失敗指針
void buildFailPointer()
{
    queue<node*> q; // 使用 BFS 的隊列
    root->fail = nullptr; // 根節點的失敗指針設為空

    // 初始化根節點的所有子節點的失敗指針
    for (int i = 0; i < 26; i++) {
        if (root->next[i] != nullptr) {
            root->next[i]->fail = root;  // 根的子節點的失敗指針設為根節點
            q.push(root->next[i]);       // 將該子節點加入隊列
        }
        else {
            root->next[i] = root;        // 若缺失該邊，則指向根節點
        }
    }

    // 使用 BFS 建立其餘節點的失敗指針
    while (!q.empty()) {
        node* current = q.front(); q.pop(); // 取出隊首節點
        for (int i = 0; i < 26; i++) {
            if (current->next[i] != nullptr) { // 若當前節點有子節點
                node* fail_node = current->fail; // 從當前節點的失敗指針開始
                // 找到祖先節點的匹配邊
                while (fail_node != nullptr && fail_node->next[i] == nullptr)
                    fail_node = fail_node->fail;
                // 若找不到匹配的祖先節點，設置為根
                current->next[i]->fail = fail_node ? fail_node->next[i] : root;
                q.push(current->next[i]); // 將子節點加入隊列
            }
            else {
                current->next[i] = current->fail->next[i]; // 缺少的邊指向失敗指針的相應子節點
            }
        }
    }
}

// 使用 AC 自動機在目標字串中進行多模式匹配
void acAutomation(char *ch)
{
    node *p = root;               // 從根節點開始
    int len = strlen(ch);         // 獲取目標字串的長度
    for (int i = 0; i < len; i++) {
        int x = ch[i] - 'a';      // 當前字母的索引值
        // 當前字母無法匹配且非根節點時，沿著失敗指針移動
        while (p->next[x] == root && p != root)
            p = p->fail;
        
        p = p->next[x];
        if (!p) p = root;         // 若找不到則返回根

        node *temp = p;
        // 沿著失敗指針查找所有匹配的模式
        while (temp != root) {    // 從當前節點沿著失敗指針向上移動
            if (temp->sum >= 0) { // 若為匹配節點
                cnt += temp->sum; // 累計匹配次數
                temp->sum = -1;   // 設置為 -1 以避免重複計算
            } else {
                break;
            }
            temp = temp->fail;    // 繼續沿失敗指針向上
        }
    }
}

int main()
{
    int T; // 測試案例數量
    cin >> T;
    while (T--)
    {
        initializeTrie();     // 初始化 Trie 樹並建立根節點
        cin >> N;             // 讀取模式字串數量
        cin.ignore();         // 忽略換行符

        // 插入所有模式字串到 Trie 樹
        for (int i = 1; i <= N; i++)
        {
            cin.getline(key, sizeof(key)); // 讀取模式字串
            insertToTrie(key);             // 插入到 Trie 樹
        }

        // 讀取目標字串
        cin.getline(pattern, sizeof(pattern));
        cnt = 0;                         // 重置匹配次數
        buildFailPointer();              // 建立失敗指針
        acAutomation(pattern);           // 進行多模式字串匹配
        cout << cnt << "\n";             // 輸出匹配到的模式字串次數
    }
    return 0;
}