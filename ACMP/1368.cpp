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

    int vertexCount, start, finish;
    cin >> vertexCount >> start >> finish;
    start--;
    finish--;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            cin >> dist[a][b];
            if (dist[a][b] == -1)
                dist[a][b] = 1e9;
        }
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (dist[a][b] > dist[a][v] + dist[v][b])
                    dist[a][b] = dist[a][v] + dist[v][b];

    cout << (dist[start][finish] != 1e9 ? dist[start][finish] : -1);
}