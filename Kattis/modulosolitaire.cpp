#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int mod, size, start;
    cin >> mod >> size >> start;

    vector<int> a(size), b(size);
    for (int i = 0; i < size; i++)
        cin >> a[i] >> b[i];

    vector<int> dist(1e6 + 1, 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (!v) {
            cout << dist[v];
            return 0;
        }

        for (int i = 0; i < a.size(); i++) {
            int to = (1LL * v * a[i] + b[i]) % mod;
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    cout << -1;
}