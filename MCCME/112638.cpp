#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<vector<int>> &hasEdge, int from, int start, int v, int dist, int targetDist, vector<int> &visited) {
    if (dist + 1 == targetDist)
        return hasEdge[v][start];

    visited[v] = 1;
    int res = 0;

    for (int to = from; to < hasEdge.size(); to++)
        if (hasEdge[v][to] && !visited[to])
            res += rec(hasEdge, from, start, to, dist + 1, targetDist, visited);

    visited[v] = 0;
    return res;
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
    int res = 0;
    for (int start = 0; start < vertexCount; start++)
        res += rec(hasEdge, start, start, start, 0, targetDist, visited);

    cout << res / 2;
}