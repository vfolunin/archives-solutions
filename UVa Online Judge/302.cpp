#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void eulerRec(map<int, set<pair<int, int>>> &graph, int v, vector<int> &cycle) {
    while (!graph[v].empty()) {
        auto [edge, to] = *graph[v].begin();
        graph[v].erase({ edge, to });
        graph[to].erase({ edge, v });
        eulerRec(graph, to, cycle);
        cycle.push_back(edge);
    }
}

bool solve() {
    map<int, set<pair<int, int>>> graph;
    vector<int> odd(45);
    int start = -1;

    while (1) {
        int a, b, edge;
        cin >> a >> b;

        if (!a && !b)
            break;

        if (start == -1)
            start = min(a, b);

        cin >> edge;

        graph[a].insert({ edge, b });
        graph[b].insert({ edge, a });
        odd[a] ^= 1;
        odd[b] ^= 1;
    }

    if (graph.empty())
        return 0;

    if (count(odd.begin(), odd.end(), 1)) {
        cout << "Round trip does not exist.\n\n";
        return 1;
    }

    vector<int> cycle;
    eulerRec(graph, start, cycle);
    reverse(cycle.begin(), cycle.end());

    for (int i = 0; i < cycle.size(); i++)
        cout << cycle[i] << (i + 1 < cycle.size() ? " " : "\n\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}