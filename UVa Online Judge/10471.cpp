#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int vertexCount, int from, vector<pair<int, int>> &edges, vector<int> &perm) {
    if (vertexCount == 2) {
        edges.push_back({ from, from + 1 });
        perm.push_back(from + 1);
        return;
    }
    rec(vertexCount / 2, from, edges, perm);
    rec(vertexCount / 2, from + vertexCount / 2, edges, perm);
    edges.push_back({ from, from + vertexCount / 2 });
    perm.push_back(from + vertexCount / 2);
}

bool solve() {
    int colorCount;
    if (!(cin >> colorCount))
        return 0;

    int vertexCount = 1 << (colorCount - 1);
    vector<pair<int, int>> edges;
    vector<int> perm;
    rec(vertexCount, 1, edges, perm);
    perm.push_back(1);

    cout << vertexCount << " " << edges.size() << "\n";
    for (auto &[a, b] : edges)
        cout << a << " " << b << "\n";
    for (int i = 0; i < perm.size(); i++)
        cout << perm[i] << (i + 1 < perm.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
