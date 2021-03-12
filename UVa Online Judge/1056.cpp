#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    map<string, int> vertexId;
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;

        if (!vertexId.count(a))
            vertexId[a] = vertexId.size();
        if (!vertexId.count(b))
            vertexId[b] = vertexId.size();

        dist[vertexId[a]][vertexId[b]] = dist[vertexId[b]][vertexId[a]] = 1;
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int res = 0;
    for (vector<int> &row : dist)
        res = max(res, *max_element(row.begin(), row.end()));

    cout << "Network " << test << ": ";
    if (res < 1e9)
        cout << res << "\n\n";
    else
        cout << "DISCONNECTED\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}