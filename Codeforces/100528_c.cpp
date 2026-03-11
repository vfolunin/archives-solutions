#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool bfs(int start, int finish) {
    vector<int> visited(1e4 + 1);
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == finish)
            return 1;

        for (int a = 1, b = v - 1; a < v; a++, b--) {
            if (a * b < visited.size() && !visited[a * b]) {
                visited[a * b] = 1;
                q.push(a * b);
            }
        }
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int start, finish;
    cin >> start >> finish;

    cout << (bfs(start, finish) ? "YES" : "NO");
}