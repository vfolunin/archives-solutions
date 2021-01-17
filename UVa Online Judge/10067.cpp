#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

istream &operator >> (istream &in, vector<int> &v) {
    for (int &x : v)
        in >> x;
    return in;
}

void solve() {
    vector<int> start(4), finish(4);
    cin >> start >> finish;

    int forbiddenCount;
    cin >> forbiddenCount;

    set<vector<int>> forbidden;
    for (int i = 0; i < forbiddenCount; i++) {
        vector<int> v(4);
        cin >> v;
        forbidden.insert(v);
    }

    map<vector<int>, int> dist = { {start, 0} };
    queue<vector<int>> q;
    q.push(start);

    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();

        vector<int> to = v;
        for (int i = 0; i < 4; i++) {
            to[i] = (v[i] + 1) % 10;
            if (!forbidden.count(to) && !dist.count(to)) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
            to[i] = (v[i] + 9) % 10;
            if (!forbidden.count(to) && !dist.count(to)) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
            to[i] = v[i];
        }
    }

    if (dist.count(finish))
        cout << dist[finish] << "\n";
    else
        cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}