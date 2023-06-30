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

    vector<pair<int, int>> edges(edgeCount);
    for (auto &[a, b] : edges) {
        cin >> a >> b;
        a--;
        b--;
    }

    vector<int> pos(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        int v;
        cin >> v;
        pos[v - 1] = i;
    }

    for (auto &[a, b] : edges) {
        if (pos[a] >= pos[b]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}