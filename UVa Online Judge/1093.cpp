#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Castle {
    int k1, k2, k3;
};

void dfs(vector<Castle> &castles, vector<vector<int>> &graph, int v, int p, vector<pair<int, int>> &people) {
    vector<pair<int, int>> childPeople;
    for (int to : graph[v]) {
        if (to == p)
            continue;
        dfs(castles, graph, to, v, people);
        childPeople.push_back(people[to]);
    }
    sort(childPeople.rbegin(), childPeople.rend());

    auto &[total, dead] = people[v];
    total = max(castles[v].k1, castles[v].k2 + castles[v].k3);
    dead = castles[v].k2 + castles[v].k3;
    for (auto &[childTotal, childDead] : childPeople) {
        total = max(total, childTotal + dead);
        dead += childDead;
    }
}

bool solve(int test) {
    int castleCount;
    cin >> castleCount;

    if (!castleCount)
        return 0;

    vector<Castle> castles(castleCount);
    for (auto &[k1, k2, k3] : castles)
        cin >> k1 >> k2 >> k3;

    vector<vector<int>> graph(castleCount);
    for (int i = 0; i < castleCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int res = 1e9;
    for (int v = 0; v < castleCount; v++) {
        vector<pair<int, int>> people(castleCount);
        dfs(castles, graph, v, -1, people);
        res = min(res, people[v].first);
    }

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}