#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 60000 + 10;
const int maxs = 100;

// Structure to hold the information
struct Info {
    char name[maxs];
    int para, pri, t;
};

Info p[maxn];
int used = 0; // Next available index in p[]
int cnt = 0;  // Counter to maintain insertion order

// Comparator for the priority queue
struct Compare {
    bool operator()(const int a, const int b) const {
        if (p[a].pri != p[b].pri)
            return p[a].pri > p[b].pri; // Min-heap based on pri
        return p[a].t > p[b].t;         // If pri equal, earlier t has higher priority
    }
};

int main(void) {
    char command[maxs];

    // Define the priority queue with the custom comparator
    priority_queue<int, vector<int>, Compare> pq;

    // Read commands until end of file
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "GET") == 0) { // GET command
            if (!pq.empty()) {
                int top_idx = pq.top(); // Get the index of the highest priority element
                pq.pop();               // Remove it from the queue
                printf("%s %d\n", p[top_idx].name, p[top_idx].para);
            } else {
                printf("EMPTY QUEUE!\n");
            }
        } else { // Insert command
            // Read the name, para, and pri for the new Info object
            scanf("%s %d %d", p[used].name, &p[used].para, &p[used].pri);
            p[used].t = cnt++; // Assign and increment the insertion order
            pq.push(used++);   // Push the index into the priority queue
        }
    }

    return 0;
}

/*
GET
PUT msg1 10 5
PUT msg2 10 4
GET
GET
GET
*/
