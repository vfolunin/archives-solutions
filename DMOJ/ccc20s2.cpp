#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    unordered_map<int, unordered_set<int>> graph;
    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            int value;
            cin >> value;

            graph[y * x].insert(value);
        }
    }

    queue<int> q;
    unordered_set<int> visited;

    q.push(1);
    visited.insert(1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == h * w) {
            cout << "yes";
            return 0;
        }

        for (int to : graph[v]) {
            if (!visited.count(to)) {
                q.push(to);
                visited.insert(to);
            }
        }
    }

    cout << "no";
}