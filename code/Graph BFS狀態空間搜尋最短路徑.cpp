#include <iostream>
#include <queue>
#include <cstring>
// #include <cmath> // Removed since we're no longer using pow
using namespace std;

// Define the node struct with an explicit constructor
struct node {
    int k, step;
    node(int k_val, int step_val) : k(k_val), step(step_val) {}
};

// Precompute powers of 10 for digit manipulation
const int power10_arr[4] = {1000, 100, 10, 1};

bool p[10000], s_array[10000]; // Renamed 's' to 's_array' to avoid confusion

// Sieve of Eratosthenes to generate prime numbers up to n
void make_sieve(int n) {
    memset(p, 0, sizeof(p));
    p[0] = 1; // 0 is not a prime
    p[1] = 1; // 1 is not a prime
    for (int i = 2; i <= n; i++) {
        if (!p[i]) {
            for (int j = i * i; j <= n; j += i)
                p[j] = 1; // Mark multiples of i as non-prime
        }
    }
}

// Function to change the digit at a specific position
int change_digit(int x, int pos, int new_digit) {
    int digits[4] = { x / 1000, (x / 100) % 10, (x / 10) % 10, x % 10 };
    digits[pos - 1] = new_digit;
    return digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
}

int main() {
    // Optimize I/O operations
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    make_sieve(9999);  // Generate primes up to 9999

    int tot;
    cin >> tot;
    while (tot--) {
        int x, y;
        cin >> x >> y;

        // Validate that both x and y are 4-digit primes
        if (x < 1000 || x > 9999 || y < 1000 || y > 9999 || p[x] || p[y]) {
            cout << "Impossible" << endl;
            continue;
        }

        // Initialize the BFS queue and visited array
        queue<node> q;
        q.push(node(x, 0)); // Use constructor to initialize node
        memset(s_array, 0, sizeof(s_array));
        s_array[x] = 1;
        int ans = -1;

        while (!q.empty()) {
            node cur = q.front();
            q.pop();

            if (cur.k == y) {
                ans = cur.step;
                break;
            }

            for (int i = 1; i <= 4; i++) {  // Change each digit position
                for (int j = 0; j <= 9; j++) {
                    // Skip if trying to set the first digit to 0 or if the digit is the same
                    if ((i == 1 && j == 0) || ((cur.k / power10_arr[i - 1]) % 10) == j)
                        continue;

                    int tk = change_digit(cur.k, i, j);

                    // Check if the new number is a prime, within range, and hasn't been visited
                    if (tk >= 1000 && tk <= 9999 && !p[tk] && !s_array[tk]) {
                        s_array[tk] = 1;
                        q.push(node(tk, cur.step + 1)); // Use constructor to initialize node
                    }
                }
            }
        }

        if (ans >= 0)
            cout << ans << "\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}
