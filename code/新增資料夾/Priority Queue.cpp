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
