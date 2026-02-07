#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, int p, vector<vector<long long>> &pathCount, int targetDist) {
    pathCount[v][0] = 1;
    for (int to : graph[v]) {
        if (to != p) {
            dfs(graph, to, v, pathCount, targetDist);
            for (int dist = 1; dist <= targetDist; dist++)
                pathCount[v][dist] += pathCount[to][dist - 1];
        }
    }
}

long long dfs2(vector<vector<int>> &graph, int v, int p, vector<vector<long long>> &pathCount, int targetDist) {
    long long res = pathCount[v][targetDist];
    long long sum = 0;
    for (int to : graph[v]) {
        if (to != p) {
            res += dfs2(graph, to, v, pathCount, targetDist);
            for (int dist1 = 1, dist2 = targetDist - 1; dist1 < targetDist; dist1++, dist2--)
                sum += pathCount[to][dist1 - 1] * (pathCount[v][dist2] - pathCount[to][dist2 - 1]);
        }
    }
    res += sum / 2;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, targetDist;
    cin >> vertexCount >> targetDist;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<long long>> pathCount(vertexCount, vector<long long>(targetDist + 1));
    dfs(graph, 0, -1, pathCount, targetDist);

    cout << dfs2(graph, 0, -1, pathCount, targetDist);
}