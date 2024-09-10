// map �O C++ STL �������p���e���A������ȹ諸�s�x�C

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;  // �ŧi�@�� map�Akey �� string�Avalue �� int

    // ���J��ȹ�
    m["apple"] = 5;
    m["banana"] = 10;
    m["orange"] = 7;

    // �ϥ� key �ӳX�ݼƾ�
    cout << "apple: " << m["apple"] << endl;  // ��X�Gapple: 5

    // �M�� map
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second << endl;  // ��X�C����ȹ�
    }

    return 0;
}
\end{lstlisting}

\section{Stack}

\begin{lstlisting}[language=C++]
// stack �O��i���X���ƾڵ��c�A�A�Ω�ݭn��i���X (LIFO) �������C

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;  // �ŧi�@�Ӿ�ƫ��� stack

    // ���J�ƾ�
    s.push(10);
    s.push(20);
    s.push(30);

    // Ū���ò����̳��ƾ�
    while (!s.empty()) {
        cout << "Top: " << s.top() << endl;  // ��X��e�̳��ƾ�
        s.pop();  // �����̳��ƾ�
    }

    return 0;
}
\end{lstlisting}

\section{Priority Queue}

\begin{lstlisting}[language=C++]
// priority_queue �O�@���u�����C�A�w�]���p�U�O�j����A�ھ��u���Ŧs�x�ƾڡC

#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;  // �ŧi�@�Ӿ�ƫ����u�����C�A�w�]���j����

    // ���J�ƾ�
    pq.push(30);
    pq.push(10);
    pq.push(20);

    // Ū���ò������C�����ƾ�
    while (!pq.empty()) {
        cout << "Top: " << pq.top() << endl;  // ��X��e���C�����ƾ�
        pq.pop();  // ���������ƾ�
    }

    return 0;
}
\end{lstlisting}

\section{Queue}

\begin{lstlisting}[language=C++]
// queue �O���i���X���ƾڵ��c�A�A�Ω�ݭn���i���X (FIFO) �������C

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;  // �ŧi�@�Ӿ�ƫ������C

    // ���J�ƾ�
    q.push(10);
    q.push(20);
    q.push(30);

    // Ū���ò��������ƾ�
    while (!q.empty()) {
        cout << "Front: " << q.front() << endl;  // ��X��e�����ƾ�
        q.pop();  // ���������ƾ�
    }

    return 0;
}
