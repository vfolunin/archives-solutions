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

    set<pair<int, int>> edges;
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        edges.insert({ a, b });
    }

    cout << (edges.size() == vertexCount * (vertexCount - 1) / 2 ? "YES" : "NO");
}