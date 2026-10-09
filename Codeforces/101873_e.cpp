#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<double>> dist(vertexCount, vector<double>(vertexCount, -1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        double weight;
        cin >> a >> b >> weight;
        a--;
        b--;

        dist[a][b] = max(dist[a][b], log(weight));
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (dist[a][v] != -1e9 && dist[v][b] != -1e9 && dist[a][b] < dist[a][v] + dist[v][b])
                    dist[a][b] = min(dist[a][v] + dist[v][b], 1e9);

    for (int v = 0; v < vertexCount; v++) {
        if (dist[v][v] > 0) {
            cout << "inadmissible";
            return 0;
        }
    }

    cout << "admissible";
}