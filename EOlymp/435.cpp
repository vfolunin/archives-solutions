#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

vector<int> getNeighbors(int v) {
    vector<int> neighbors;
    string s = to_string(v);
    for (int i = 0; i < s.size(); i++) {
        string t = s;
        for (t[i] = '0'; t[i] <= '9'; t[i]++) {
            int to = stoi(t);
            if (1000 <= to && to != v && isPrime(to))
                neighbors.push_back(to);
        }
    }
    return neighbors;
}

int bfs(int start, int finish) {
    vector<int> dist(1e5, 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == finish)
            return dist[v];

        for (int to : getNeighbors(v)) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return -1;
}

void solve() {
    int start, finish;
    cin >> start >> finish;

    int dist = bfs(start, finish);

    if (dist != -1)
        cout << dist << "\n";
    else
        cout << "Impossible\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}