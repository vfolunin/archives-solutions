#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int edgeCount;
    if (!(cin >> edgeCount))
        return 0;

    int vertexCount = 0;
    vector<vector<long long>> ways(30, vector<long long>(30));

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        vertexCount = max(vertexCount, max(a, b) + 1);
        ways[a][b]++;
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                ways[a][b] += ways[a][v] * ways[v][b];

    for (int v = 0; v < vertexCount; v++)
        if (ways[v][v])
            for (int a = 0; a < vertexCount; a++)
                for (int b = 0; b < vertexCount; b++)
                    if (ways[a][v] && ways[v][b])
                        ways[a][b] = -1;

    cout << "matrix for city " << test << "\n";
    for (int a = 0; a < vertexCount; a++) 
        for (int b = 0; b < vertexCount; b++)
            cout << ways[a][b] << (b + 1 < vertexCount ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}