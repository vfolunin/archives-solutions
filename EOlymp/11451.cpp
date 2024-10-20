#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    vector<string> vertexName(vertexCount);
    map<string, int> vertexId;
    for (string &name : vertexName) {
        cin >> name;
        vertexId[name] = vertexId.size();
    }

    int edgeCount;
    cin >> edgeCount;

    vector<set<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;
        graph[vertexId[a]].insert(vertexId[b]);
    }

    vector<int> inDegree(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        for (int to : graph[v])
            inDegree[to]++;

    set<pair<int, int>> q;
    for (int v = 0; v < vertexCount; v++)
        q.insert({ inDegree[v], v });

    vector<int> order;
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        order.push_back(v);

        for (int to : graph[v]) {
            q.erase({ inDegree[to], to });
            inDegree[to]--;
            q.insert({ inDegree[to], to });
        }
    }

    cout << "Case #" << test << ": ";
    cout << "Dilbert should drink beverages in this order:";
    for (int v : order)
        cout << " " << vertexName[v];
    cout << ".\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}