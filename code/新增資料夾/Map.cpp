// map 是 C++ STL 中的關聯式容器，提供鍵值對的存儲。

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;  // 宣告一個 map，key 為 string，value 為 int

    // 插入鍵值對
    m["apple"] = 5;
    m["banana"] = 10;
    m["orange"] = 7;

    // 使用 key 來訪問數據
    cout << "apple: " << m["apple"] << endl;  // 輸出：apple: 5

    // 遍歷 map
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second << endl;  // 輸出每個鍵值對
    }

    return 0;
}
\end{lstlisting}

\section{Stack}

\begin{lstlisting}[language=C++]
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
\end{lstlisting}

\section{Priority Queue}

\begin{lstlisting}[language=C++]
// priority_queue 是一個優先隊列，預設情況下是大頂堆，根據優先級存儲數據。

#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;  // 宣告一個整數型的優先隊列，預設為大頂堆

    // 插入數據
    pq.push(30);
    pq.push(10);
    pq.push(20);

    // 讀取並移除隊列頂部數據
    while (!pq.empty()) {
        cout << "Top: " << pq.top() << endl;  // 輸出當前隊列頂部數據
        pq.pop();  // 移除頂部數據
    }

    return 0;
}
\end{lstlisting}

\section{Queue}

\begin{lstlisting}[language=C++]
// queue 是先進先出的數據結構，適用於需要先進先出 (FIFO) 的場景。

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;  // 宣告一個整數型的隊列

    // 插入數據
    q.push(10);
    q.push(20);
    q.push(30);

    // 讀取並移除隊首數據
    while (!q.empty()) {
        cout << "Front: " << q.front() << endl;  // 輸出當前隊首數據
        q.pop();  // 移除隊首數據
    }

    return 0;
}
