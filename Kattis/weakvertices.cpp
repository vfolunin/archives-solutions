#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (vertexCount == -1)
        return 0;

    vector<vector<int>> adj(vertexCount, vector<int>(vertexCount));
    for (int v = 0; v < vertexCount; v++)
        for (int to = 0; to < vertexCount; to++)
            cin >> adj[v][to];

    for (int v = 0; v < vertexCount; v++) {
        bool weak = true;
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                weak &= v == a || v == b || a == b || !adj[v][a] || !adj[v][b] || !adj[a][b];

        if (weak)
            cout << v << " ";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}