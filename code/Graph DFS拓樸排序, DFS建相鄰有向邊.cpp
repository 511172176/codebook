#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <string> // Ensure you have included <string>

using namespace std;

// Function to perform DFS to check if target is reachable from current
bool is_reachable(int current, int target, int N, int g[][100], bool visited[]) {
    if (current == target) return true;
    visited[current] = true;
    for (int i = 0; i < N; i++) {
        if (g[current][i] && !visited[i]) {
            if (is_reachable(i, target, N, g, visited))
                return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    while (cin >> N >> K) {
        if (N == 0 && K == 0) break; // Terminate when N and K are both zero

        // Initialize adjacency matrix and in-degree count
        int g[100][100];
        memset(g, 0, sizeof(g));
        vector<int> in_degree(N, 0);

        bool determined = false;
        bool inconsistent = false;
        string relation;

        for (int i = 0; i < K; i++) {
            cin >> relation;
            if (relation.size() < 3 || (relation[1] != '<' && relation[1] != '>')) {
                // Handle invalid input format
                cout << "Invalid relation format." << endl;
                inconsistent = true;
                break;
            }

            char a = relation[0];
            char b = relation[2];
            char op = relation[1];
            int x, y;

            // Determine the direction of the relation
            if (op == '<') {
                x = a - 'A';
                y = b - 'A';
            }
            else { // op == '>'
                x = b - 'A';
                y = a - 'A';
            }

            // Check if adding edge x -> y creates a cycle
            bool visited[100];
            memset(visited, false, sizeof(visited));
            if (is_reachable(y, x, N, g, visited)) {
                // Adding edge x->y would create a cycle
                cout << "Inconsistency found after " << (i + 1) << " relations." << endl;

                // Read and discard remaining relations for this test case
                for (int j = i + 1; j < K; j++) {
                    cin >> relation;
                }

                inconsistent = true;
                break;
            }

            // Add the edge x -> y
            g[x][y] = 1;
            in_degree[y]++;

            // Perform Topological Sort to check if a unique sequence is determined
            // Create a copy of in_degree to manipulate
            vector<int> in_copy = in_degree;
            queue<int> Q;
            vector<int> result;

            // Enqueue all nodes with in-degree 0
            for (int node = 0; node < N; node++) {
                if (in_copy[node] == 0) {
                    Q.push(node);
                }
            }

            bool multiple = false; // Flag to check if multiple sequences are possible

            while (!Q.empty()) {
                if (Q.size() > 1) {
                    multiple = true; // More than one node with in-degree 0 implies multiple sequences
                }

                int current = Q.front();
                Q.pop();
                result.push_back(current);

                // Decrease in-degree of neighboring nodes
                for (int neighbor = 0; neighbor < N; neighbor++) {
                    if (g[current][neighbor]) {
                        in_copy[neighbor]--;
                        if (in_copy[neighbor] == 0) {
                            Q.push(neighbor);
                        }
                    }
                }
            }

            // Check if a unique sorted sequence is determined
            if (result.size() == N && !multiple) {
                cout << "Sorted sequence determined after " << (i + 1) << " relations: ";
                // Replace range-based for loop with traditional for loop
                for (size_t idx = 0; idx < result.size(); idx++) {
                    int node = result[idx];
                    cout << char('A' + node);
                }
                cout << "." << endl;

                // Read and discard remaining relations for this test case
                for (int j = i + 1; j < K; j++) {
                    cin >> relation;
                }

                determined = true;
                break;
            }
        }

        // If no inconsistency or unique sequence was found after processing all relations
        if (!inconsistent && !determined) {
            cout << "Sorted sequence cannot be determined." << endl;
        }
    }

    return 0;
}
