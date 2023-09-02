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

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        graph[a - 1].push_back(b - 1);
    }

    cout << vertexCount << "\n";
    for (vector<int> &adj : graph) {
        cout << adj.size() << " ";

        sort(adj.begin(), adj.end());

        for (int v : adj)
            cout << v + 1 << " ";
        cout << "\n";
    }
}