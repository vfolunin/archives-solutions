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

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int weight;
            cin >> weight;

            if (weight)
                dist[a][b] = weight;
            else if (a == b)
                dist[a][b] = 0;
        }
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (dist[a][v] != 1e9 && dist[v][b] != 1e9)
                    dist[a][b] = max<int>(-1e9, min(dist[a][b], dist[a][v] + dist[v][b]));

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (dist[a][v] != 1e9 && dist[v][b] != 1e9 && dist[v][v] < 0)
                    dist[a][b] = -1e9;

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            if (dist[a][b] == 1e9)
                cout << "0 ";
            else if (dist[a][b] != -1e9)
                cout << "1 ";
            else
                cout << "2 ";
        }
        cout << "\n";
    }
}