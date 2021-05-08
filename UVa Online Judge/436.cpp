#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    map<string, int> vertexId;
    for (int i = 0; i < vertexCount; i++) {
        string name;
        cin >> name;
        vertexId[name] = vertexId.size();
    }

    vector<vector<double>> dist(vertexCount, vector<double>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 1;

    int edgeCount;
    cin >> edgeCount;

    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        double w;
        cin >> a >> w >> b;
        dist[vertexId[a]][vertexId[b]] = -log10(w);
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (dist[a][v] != 1e9 && dist[v][b] != 1e9 && dist[a][b] > dist[a][v] + dist[v][b])
                    dist[a][b] = dist[a][v] + dist[v][b];

    bool res = 0;
    for (int v = 0; v < vertexCount; v++)
        res |= dist[v][v] < 0;

    cout << "Case " << test << ": " << (res ? "Yes\n" : "No\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}