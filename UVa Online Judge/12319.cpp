#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> readDist(int vertexCount) {
    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;
    for (int i = 0; i < vertexCount; i++) {
        int v;
        cin >> v;
        while (cin.peek() == ' ') {
            int to;
            cin >> to;
            dist[v - 1][to - 1] = 1;
        }
    }
    return dist;
}

void floyd(vector<vector<int>> &dist) {
    for (int v = 0; v < dist.size(); v++)
        for (int a = 0; a < dist.size(); a++)
            for (int b = 0; b < dist.size(); b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> dist1 = readDist(vertexCount);
    floyd(dist1);

    vector<vector<int>> dist2 = readDist(vertexCount);
    floyd(dist2);

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            if (a * dist1[i][j] + b < dist2[i][j]) {
                cout << "No\n";
                return 1;
            }
        }
    }

    cout << "Yes\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}