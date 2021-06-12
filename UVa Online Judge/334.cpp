#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getId(map<string, int> &vertexId, string &name) {
    if (!vertexId.count(name))
        vertexId[name] = vertexId.size();
    return vertexId[name];
}

string getName(map<string, int> &vertexId, int id) {
    for (auto &[name, i] : vertexId)
        if (id == i)
            return name;
    return "";
}

bool solve(int test) {
    int chainCount;
    cin >> chainCount;

    if (!chainCount)
        return 0;

    map<string, int> vertexId;
    vector<pair<int, int>> edges;
    for (int i = 0; i < chainCount; i++) {
        int chainSize;
        cin >> chainSize;

        string from, to;
        for (int i = 0; i < chainSize; i++) {
            from = to;
            cin >> to;
            getId(vertexId, to);
            if (i)
                edges.push_back({ getId(vertexId, from), getId(vertexId, to) });
        }
    }

    int edgeCount;
    cin >> edgeCount;

    for (int i = 0; i < edgeCount; i++) {
        string from, to;
        cin >> from >> to;
        edges.push_back({ getId(vertexId, from), getId(vertexId, to) });
    }

    int vertexCount = vertexId.size();
    vector<vector<int>> reachable(vertexCount, vector<int>(vertexCount));
    for (auto &[a, b] : edges)
        reachable[a][b] = 1;

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                reachable[a][b] |= reachable[a][v] && reachable[v][b];

    vector<pair<int, int>> concurrent;
    for (int a = 0; a < vertexCount; a++)
        for (int b = a + 1; b < vertexCount; b++)
            if (!reachable[a][b] && !reachable[b][a])
                concurrent.push_back({ a, b });

    cout << "Case " << test << ", ";
    if (concurrent.empty()) {
        cout << "no concurrent events.\n";
    } else {
        cout << concurrent.size() << " concurrent events:\n";
        cout << "(" << getName(vertexId, concurrent[0].first) << "," << getName(vertexId, concurrent[0].second) << ") ";
        if (concurrent.size() > 1)
            cout << "(" << getName(vertexId, concurrent[1].first) << "," << getName(vertexId, concurrent[1].second) << ") ";
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}