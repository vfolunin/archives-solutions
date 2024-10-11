#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

void printPath(map<pair<int, int>, tuple<int, int, string>> &from, int a, int b) {
    vector<string> path;
    while (from.count({ a, b })) {
        auto &[pa, pb, ps] = from[{ a, b }];
        a = pa;
        b = pb;
        path.push_back(ps);
    }

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << "\n";
}

void bfs(int capacityA, int capacityB, int target) {
    const int INF = 1e9;

    map<pair<int, int>, int> dist;
    map<pair<int, int>, tuple<int, int, string>> from;
    queue<pair<int, int>> q;

    dist[{ 0, 0 }] = 0;
    q.push({ 0, 0 });

    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();

        if (a == target || b == target) {
            printPath(from, a, b);
            return;
        }

        vector<tuple<int, int, string>> to = {
            { 0, b, "A>" },
            { a, 0, "B>" },
            { capacityA, b, ">A" },
            { a, capacityB, ">B" }
        };
        int deltaAB = min(a, capacityB - b);
        to.push_back({ a - deltaAB, b + deltaAB, "A>B" });
        int deltaBA = min(capacityA - a, b);
        to.push_back({ a + deltaBA, b - deltaBA, "B>A" });

        for (auto &[ta, tb, ts] : to) {
            if (!dist.count({ ta, tb })) {
                dist[{ ta, tb }] = dist[{ a, b }] + 1;
                from[{ ta, tb }] = { a, b, ts };
                q.push({ ta, tb });
            }
        }
    }

    cout << "Impossible";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int capacityA, capacityB, target;
    cin >> capacityA >> capacityB >> target;

    bfs(capacityA, capacityB, target);
}