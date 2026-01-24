#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, start;
    cin >> vertexCount >> start;
    start--;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 1;

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;

            if (hasEdge)
                dist[a][b] = 1;
        }
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    cout << max_element(dist[start].begin(), dist[start].end()) - dist[start].begin() + 1;
}