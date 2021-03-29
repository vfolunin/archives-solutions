#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> degree;
        graph[v].resize(degree);
        for (int &to : graph[v])
            cin >> to;
    }

    vector<long long> ways(vertexCount);
    long long res = 0;

    ways[0] = 1;
    for (int v = 0; v < vertexCount; v++) {
        for (int to : graph[v])
            ways[to] += ways[v];
        if (graph[v].empty())
            res += ways[v];
    }

    if (test)
        cout << "\n";
    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}