#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<int> &a) {
    vector<int> dist(a.size(), 1e9);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == a.size() - 1)
            return dist[v];

        for (int to : { v + 1, v + a[v] }) {
            if (0 <= to && to < a.size() && dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return -1;
}

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;
    a.push_back(0);

    cout << bfs(a) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}