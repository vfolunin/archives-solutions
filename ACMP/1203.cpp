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

    vector<vector<int>> graph(vertexCount, vector<int>(vertexCount));
    for (int v = 0; v < vertexCount; v++) {
        int size;
        cin >> size;

        for (int i = 0; i < size; i++) {
            int to;
            cin >> to;

            graph[v][to - 1] = 1;
        }
    }

    cout << vertexCount << "\n";
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++)
            cout << graph[a][b] << " ";
        cout << "\n";
    }
}