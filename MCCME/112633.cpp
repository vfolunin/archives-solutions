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

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> dist[a][b];

    vector<int> path;
    for (int value; cin >> value; )
        path.push_back(value - 1);

    int res = 0;
    for (int i = 0; i + 1 < path.size(); i++) {
        if (!dist[path[i]][path[i + 1]]) {
            cout << 0;
            return 0;
        }
        res += dist[path[i]][path[i + 1]];
    }

    cout << res;
}