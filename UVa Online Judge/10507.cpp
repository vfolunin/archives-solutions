#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    string start;
    cin >> start;

    vector<vector<int>> graph(26);
    for (int i = 0; i < edgeCount; i++) {
        char a, b;
        cin >> a >> b;
        graph[a - 'A'].push_back(b - 'A');
        graph[b - 'A'].push_back(a - 'A');
    }

    set<int> active;
    for (char c : start)
        active.insert(c - 'A');

    vector<int> activeNeighbors(26);
    for (char c : start)
        for (int v : graph[c - 'A'])
            activeNeighbors[v]++;
    
    set<pair<int, int>> q;
    for (int v = 0; v < 26; v++)
        if (!active.count(v) && activeNeighbors[v])
            q.insert({ activeNeighbors[v], v });

    int res = 0;
    while (active.size() < vertexCount) {
        set<int> activating;
        while (!q.empty() && (--q.end())->first >= 3) {
            auto [_, v] = *--q.end();
            q.erase(--q.end());
            activating.insert(v);
        }

        if (activating.empty()) {
            cout << "THIS BRAIN NEVER WAKES UP\n";
            return 1;
        }

        for (int v : activating) {
            active.insert(v);
            for (int to : graph[v]) {
                q.erase({ activeNeighbors[to], to });
                activeNeighbors[to]++;
                if (!active.count(to) && activeNeighbors[to])
                    q.insert({ activeNeighbors[to], to });
            }
        }

        res++;
    }

    cout << "WAKE UP IN, " << res << ", YEARS\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}