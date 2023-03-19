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

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    vector<vector<int>> next(vertexCount, vector<int>(vertexCount, -1));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int weight;
            cin >> weight;

            if (weight) {
                dist[a][b] = weight;
                next[a][b] = b;
            } else if (a == b) {
                dist[a][b] = 0;
            }
        }
    }
    
    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = 0; b < vertexCount; b++) {
                if (dist[a][v] != 1e9 && dist[v][b] != 1e9 && dist[a][b] > dist[a][v] + dist[v][b]) {
                    dist[a][b] = dist[a][v] + dist[v][b];
                    next[a][b] = next[a][v];
                }
            }
        }
    }

    cout << dist[start][finish] << "\n";
    for (int v = start; v != -1; v = next[v][finish])
        cout << v + 1 << " ";
}