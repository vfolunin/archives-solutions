#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<vector<int>, int> dijkstra(const vector<int> &cap) {
    map<vector<int>, int> dist;
    set<pair<int, vector<int>>> q;

    dist[{0, 0, cap[2]}] = 0;
    q.insert({ 0, {0, 0, cap[2]} });

    while (!q.empty()) {
        vector<int> v = q.begin()->second;
        q.erase(q.begin());

        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (a == b)
                    continue;

                int delta = min(v[a], cap[b] - v[b]);

                vector<int> to = v;
                to[a] -= delta;
                to[b] += delta;

                if (!dist.count(to) || dist[to] > dist[v] + delta) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + delta;
                    q.insert({ dist[to], to });
                }
            }
        }
    }

    return dist;
}

void solve() {
    int a, b, c, target;
    cin >> a >> b >> c >> target;

    map<vector<int>, int> dist = dijkstra({ a, b, c });

    int res = -1, resDist = -1;
    for (auto &[triplet, dist] : dist) {
        for (int tripletElement : triplet) {
            if (tripletElement <= target) {
                if (target - res > target - tripletElement ||
                    target - res == target - tripletElement && resDist > dist) {
                    res = tripletElement;
                    resDist = dist;
                }
            }
        }
    }

    cout << resDist << " " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}