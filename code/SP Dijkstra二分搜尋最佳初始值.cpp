##include <bits/stdc++.h>
using namespace std;

// Function to convert character to index
int turn(char x){
    if(x >= 'A' && x <= 'Z') return x - 'A' + 1;    // 'A'-'Z' -> 1-26
    if(x >= 'a' && x <= 'z') return x - 'a' + 27;   // 'a'-'z' -> 27-52
    return -1; // Invalid character
}

// Check function: Determines the maximum cargo that can reach 'to' from 'from' with starting cargo 'o'
int check(int from, int to, int o, bool go[][55]){
    int g[55];
    memset(g, 0, sizeof(g));         // Initialize cargo for each node to 0
    bool flag[55];
    memset(flag, false, sizeof(flag)); // Initialize visit flags to false
    g[from] = o;                      // Set starting cargo at 'from' node

    while(true){
        int w = 0, next = -1;
        // Find the unflagged node with the highest cargo
        for(int i = 1; i <= 52; i++){
            if(!flag[i] && g[i] > w){
                next = i;
                w = g[i];
            }
        }

        if(next == -1) break; // No more nodes to process
        flag[next] = true;     // Mark the node as processed

        // Update cargo for connected nodes
        for(int i = 1; i <= 52; i++){
            if(go[next][i]){
                int reduction;
                if(i < 27){
                    reduction = (w + 19) / 20; // Equivalent to ceil(w / 20)
                }
                else{
                    reduction = 1;
                }
                int tmp = w - reduction;
                if(tmp > g[i]){
                    g[i] = tmp; // Update cargo if the new value is higher
                }
            }
        }
    }

    return g[to]; // Return the cargo at the destination node
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); // Fast I/O

    int T; // Number of connections
    int tot = 0; // Test case counter

    while(cin >> T){
        if(T == -1) break; // Termination condition

        // Initialize adjacency matrix
        bool go[55][55];
        memset(go, false, sizeof(go));

        // Read T connections
        for(int i = 0; i < T; i++){
            char x, y;
            cin >> x >> y;
            int a = turn(x);
            int b = turn(y);
            if(a == -1 || b == -1){
                // Invalid characters, skip this connection
                continue;
            }
            go[a][b] = go[b][a] = true; // Bidirectional connection
        }

        // Read Tot (required cargo)
        int Tot;
        cin >> Tot;

        // Read source and destination characters
        char fromChar, toChar;
        cin >> fromChar >> toChar;
        int from = turn(fromChar);
        int to = turn(toChar);

        if(from == -1 || to == -1){
            // Invalid source or destination nodes
            tot++;
            cout << "Case " << tot << ": Impossible\n";
            continue;
        }

        // Binary search to find the minimal starting cargo 'o' such that check(from, to, o) >= Tot
        int l = 1, r = (1 << 20); // Search range: 1 to 1048576
        while(l < r){
            int mid = (l + r - 1) / 2; // Midpoint calculation
            int cargo = check(from, to, mid, go);
            if(cargo >= Tot){
                r = mid; // Possible answer found, search lower half
            }
            else{
                l = mid + 1; // Need a higher starting cargo, search upper half
            }
        }

        // After binary search, 'l' should be the minimal 'o' such that check(from, to, l) >= Tot
        // Verify the result
        int finalCargo = check(from, to, l, go);
        if(finalCargo >= Tot){
            tot++;
            cout << "Case " << tot << ": " << l << "\n";
        }
        else{
            // If even the maximum cargo doesn't meet the requirement
            tot++;
            cout << "Case " << tot << ": Impossible\n";
        }
    }

    return 0;
}

/*
1
a Z
19 a Z
5
A D
D X
A b
b c
c X
39 A X
-1
*/
