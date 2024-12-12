#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m;
    cin >> h >> m;
    return h * 60 + m;
}

void writeTime(int t) {
    cout << t / 60 << " " << t % 60 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int clientCount;
    cin >> clientCount;

    multiset<int> q = { 0, 0, 0 };

    for (int i = 0; i < clientCount; i++) {
        int tIn = readTime();
        int tOut = max(*q.begin(), tIn) + 30;

        q.erase(q.begin());
        q.insert(tOut);

        writeTime(tOut);
    }
}