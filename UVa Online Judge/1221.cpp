#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    int aSize, bSize;
    vector<vector<int>> g;
    vector<int> pairFromA;
    vector<int> visited;

    Graph(int aSize, int bSize) : aSize(aSize), bSize(bSize), g(aSize + bSize) {}

    void addEdge(int a, int b) {
        g[a].push_back(b);
    }

    bool dfs(int vFromA) {
        visited[vFromA] = 1;
        for (int vFromB : g[vFromA]) {
            int &to = pairFromA[vFromB];
            if (to == -1 || !visited[to] && dfs(to)) {
                to = vFromA;
                return 1;
            }
        }
        return 0;
    }

    int kuhn() {
        pairFromA.assign(bSize, -1);
        for (int vFromA = 0; vFromA < aSize; vFromA++) {
            visited.assign(aSize, 0);
            dfs(vFromA);
        }
        return pairFromA.size() - count(pairFromA.begin(), pairFromA.end(), -1);
    }
};

bool solve() {
    int hCount, aCount;
    cin >> hCount >> aCount;

    if (!hCount && !aCount)
        return 0;

    vector<int> hInit(hCount);
    vector<int> hRate(hCount);
    for (int i = 0; i < hCount; i++)
        cin >> hInit[i] >> hRate[i];

    vector<int> aInit(aCount);
    vector<int> aRate(aCount);
    for (int i = 0; i < aCount; i++)
        cin >> aInit[i] >> aRate[i];

    vector<vector<int>> dist(hCount, vector<int>(aCount));
    for (vector<int> &row : dist)
        for (int &d : row)
            cin >> d;

    if (hCount < aCount) {
        cout << "IMPOSSIBLE\n";
        return 1;
    }

    int l = -1, r = 1e6;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;

        Graph graph(hCount, aCount);
        for (int h = 0; h < hCount; h++) {
            for (int a = 0; a < aCount; a++) {
                long long hPower = hInit[h] + 1LL * hRate[h] * (m - dist[h][a]);
                long long aPower = aInit[a] + 1LL * aRate[a] * m;
                if (hPower >= aPower)
                    graph.addEdge(h, a);
            }
        }

        if (graph.kuhn() == aCount)
            r = m;
        else
            l = m;
    }

    if (r != 1e6)
        cout << r << "\n";
    else
        cout << "IMPOSSIBLE\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}