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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount, vector<int>(vertexCount));
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
    }

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++)
            cout << graph[a][b] << " ";
        cout << "\n";
    }
}