#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int reverse(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}

int bfs(int a, int b) {
    map<int, int> dist;
    queue<int> q;

    dist[a] = 0;
    q.push(a);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == b)
            break;

        for (int to : { v + 1, reverse(v) }) {
            if (!dist.count(to)) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist[b];
}

void solve() {
    int a, b;
    cin >> a >> b;

    cout << bfs(a, b) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}