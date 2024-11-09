#include <iostream>
#include <string>
using namespace std;

string s;
int i, n = 0, height1, height2;

void work(int level1, int level2) {
    int tempson = 0;
    while (s[i] == 'd') {
        i++;
        tempson++;
        work(level1 + 1, level2 + tempson);
    }
    height1 = max(height1, level1);
    height2 = max(height2, level2);
    if (s[i] == 'u') i++;
}

int main() {
    while (cin >> s && s != "#") {
        i = height1 = height2 = 0;
        work(0, 0);
        cout << "Tree " << ++n << ": " << height1 << " => " << height2 << endl;
    }
    return 0;
}
