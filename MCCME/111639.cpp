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

    vector<vector<int>> res(vertexCount, vector<int>(vertexCount));
    for (int v = 0; v < vertexCount; v++) {
        int adjCount;
        cin >> adjCount;
        for (int i = 0; i < adjCount; i++) {
            int to;
            cin >> to;
            res[v][to - 1] = 1;
        }
    }

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++)
            cout << res[a][b] << " ";
        cout << "\n";
    }
}