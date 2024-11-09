#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int MAXN = 1e6 + 6;    // 適當調整大小，根據需要
int cnt;                     // 記錄匹配模式字串的次數

// 節點結構體定義
struct node {
    int sum; // 該節點的匹配次數
    node *next[26]; // 指向子節點的指標陣列
    node *fail; // 失敗指針

    node() : sum(0), fail(nullptr) {
        for(int i = 0; i < 26; i++) next[i] = nullptr;
    }
};
node *root;
char key[70];
char pattern[MAXN];
int N;

// 插入模式字串到 Trie 樹中
void Insert(char *s)
{
    node *p = root; // 開始於 Trie 樹的根節點
    for (int i = 0; s[i]; i++) {
        int x = s[i] - 'a'; // 計算字元索引
        if (p->next[x] == nullptr) {
            p->next[x] = new node(); // 創建新節點
        }
        p = p->next[x]; // 移動到子節點
    }
    p->sum++; // 該節點匹配次數加 1
}

// 建立失敗指針
void build_fail_pointer()
{
    queue<node*> q; // 使用 C++ 的隊列
    root->fail = nullptr; // 根節點的失敗指針指向空

    // 將根節點的子節點加入隊列並設置失敗指針
    for (int i = 0; i < 26; i++) {
        if (root->next[i] != nullptr) {
            // 如果根的某子節點存在，將該子節點的失敗指針設為根節點
            root->next[i]->fail = root;
            q.push(root->next[i]); // 將該子節點加入隊列
        }
        else {
            root->next[i] = root; // 優化，缺失的邊指向根節點
        }
    }

    // BFS 建立失敗指針
    while (!q.empty()) {
        node* current = q.front(); q.pop(); // 取出隊首節點
        for (int i = 0; i < 26; i++) {
            if (current->next[i] != nullptr) { // 若存在子節點
                // 設置失敗指針
                node* fail_node = current->fail; // 從當前節點的失敗指針開始
                // 找到某個祖先節點的匹配邊
                while (fail_node != nullptr && fail_node->next[i] == nullptr)
                    fail_node = fail_node->fail; // 繼續沿著失敗指針向上
                if (fail_node == nullptr)
                    current->next[i]->fail = root; // 若找不到則指向根節點
                else
                    current->next[i]->fail = fail_node->next[i]; // 否則設置為找到的節點
                q.push(current->next[i]); // 將該子節點加入隊列
            }
            else {
                // 若當前節點缺少某字母的邊，將其指向失敗指針的相應子節點
                current->next[i] = current->fail->next[i];
            }
        }
    }
}


// 在目標字串中運行 AC 自動機，進行多模式匹配
void ac_automation(char *ch) {
    node *p = root; // 從根節點開始
    int len = strlen(ch); // 目標字串的長度
    for (int i = 0; i < len; i++) {
        int x = ch[i] - 'a'; // 當前字元索引
        while (p->next[x] == root && p != root)
            p = p->fail;

        p = p->next[x];
        if (!p)
            p = root;

        node *temp = p;
        while (temp != root) { // 往上沿失敗指針累計所有匹配結果
            if (temp->sum >= 0) { // 如果是匹配節點
                cnt += temp->sum; // 累計匹配次數
                temp->sum = -1; // 設置為 -1 以避免重複計算
            }
            else
                break;
            temp = temp->fail; // 沿失敗指針往上跳轉
        }
    }
}

int main()
{
    int T; // 測試案例數量
    cin >> T;
    while (T--)
    {
        // 建立根節點
        root = new node();
        // 讀取模式字串數量
        cin >> N;
        cin.ignore(); // 忽略換行符

        for (int i = 1; i <= N; i++)
        {
            // 讀取模式字串
            cin.getline(key, sizeof(key));
            Insert(key); // 將模式字串插入到 Trie 樹中
        }
        // 讀取目標字串
        cin.getline(pattern, sizeof(pattern));
        cnt = 0;
        build_fail_pointer(); // 建立失敗指針
        ac_automation(pattern); // 使用 AC 自動機進行匹配
        cout << cnt << "\n"; // 輸出匹配到的模式字串次數
    }
    return 0;
}

/*
輸入範例：
1
5
she
he
say
shr
her
yasherhs

預期輸出：
3
*/
