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

    vector<vector<int>> res(vertexCount, vector<int>(edgeCount));
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        res[a - 1][i] = res[b - 1][i] = 1;
    }

    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < edgeCount; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}