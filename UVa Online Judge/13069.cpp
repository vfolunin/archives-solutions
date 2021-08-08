#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int start, int finish) {
    vector<int> dist(10000, 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (1) {
        int v = q.front();
        q.pop();

        if (v == finish)
            return dist[v];

        vector<int> neighbors = { (v + 1) % 10000, (v * 2) % 10000, v / 3 };
        for (int to : neighbors) {
            if (dist[to] == 1e9) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
}

bool solve() {
    int a, b;
    if (!(cin >> a >> b))
        return 0;

    cout << bfs(a, b) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}