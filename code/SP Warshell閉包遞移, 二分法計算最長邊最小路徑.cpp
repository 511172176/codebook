#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

const int MAX_N = (1 << 9) + 1;
double L[MAX_N][MAX_N];  // Distance matrix
bool con[MAX_N][MAX_N];  // Connection matrix

int main() {
    int N, testCase = 0;
    while (cin >> N && N != 0) {
        vector<double> x(N), y(N);

        // Read coordinates of each stone
        for (int i = 0; i < N; ++i) {
            cin >> x[i] >> y[i];
        }

        // Calculate the distance matrix L
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                L[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            }
        }

        // Binary search for the minimum distance
        double l = 0, r = 1e5;
        while (r - l > 1e-5) {
            double mid = (l + r) / 2;

            // Initialize the connection matrix based on mid distance
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    con[i][j] = (L[i][j] <= mid);
                }
            }

            // Floyd-Warshall algorithm to determine reachability
            for (int k = 0; k < N; ++k) {
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < N; ++j) {
                        con[i][j] = con[i][j] || (con[i][k] && con[k][j]);
                    }
                }
            }

            // Check if the first and second stones are connected
            if (con[0][1]) {
                r = mid;
            } else {
                l = mid;
            }
        }

        // Output the result with three decimal precision
        cout << "Scenario #" << ++testCase << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << l << endl;
        cout << endl;
    }
    return 0;
}
