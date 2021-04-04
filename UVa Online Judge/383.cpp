#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int vertexCount, edgeCount, queryCount;
    cin >> vertexCount >> edgeCount >> queryCount;

    map<string, int> vertexId;
    for (int i = 0; i < vertexCount; i++) {
        string name;
        cin >> name;
        vertexId[name] = vertexId.size();
    }

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;
    for (int i = 0; i < edgeCount; i++) {
        string nameA, nameB;
        cin >> nameA >> nameB;
        dist[vertexId[nameA]][vertexId[nameB]] = 1;
        dist[vertexId[nameB]][vertexId[nameA]] = 1;
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    cout << "DATA SET  " << test << "\n\n";
    for (int i = 0; i < queryCount; i++) {
        int weight;
        string nameA, nameB;
        cin >> weight >> nameA >> nameB;

        if (dist[vertexId[nameA]][vertexId[nameB]] != 1e9)
            cout << "$" << dist[vertexId[nameA]][vertexId[nameB]] * weight * 100 << "\n";
        else
            cout << "NO SHIPMENT POSSIBLE\n";
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << "SHIPPING ROUTES OUTPUT\n\n";
    for (int test = 1; test <= n; test++)
        solve(test);
    cout << "END OF OUTPUT\n";
}