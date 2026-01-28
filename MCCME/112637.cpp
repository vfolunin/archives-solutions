#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<vector<int>> &hasEdge, int start, int v, int dist, int targetDist, vector<int> &visited, set<pair<int, int>> &pairs) {
    visited[v] = 1;

    if (dist == targetDist) {
        if (start < v)
            pairs.insert({ start, v });
    } else {
        for (int to = 0; to < hasEdge.size(); to++)
            if (hasEdge[v][to] && !visited[to])
                rec(hasEdge, start, to, dist + 1, targetDist, visited, pairs);
    }

    visited[v] = 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> hasEdge(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> hasEdge[a][b];

    int targetDist;
    cin >> targetDist;

    vector<int> visited(vertexCount);
    set<pair<int, int>> pairs;
    for (int start = 0; start < vertexCount; start++)
        rec(hasEdge, start, start, 0, targetDist + 1, visited, pairs);

    if (pairs.empty()) {
        cout << 0;
    } else {
        for (auto &[a, b] : pairs)
            cout << a + 1 << " " << b + 1 << "\n";
    }
}