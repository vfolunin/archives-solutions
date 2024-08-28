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

    vector<vector<int>> reachable(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> reachable[a][b];

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                reachable[a][b] |= reachable[a][v] && reachable[v][b];

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++)
            cout << reachable[a][b] << " ";
        cout << "\n";
    }
}