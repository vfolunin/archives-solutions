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

    vector<pair<int, int>> edges;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;

            if (hasEdge)
                edges.push_back({ a, b });
        }
    }

    cout << vertexCount << " " << edges.size() << "\n";
    for (auto &[a, b] : edges)
        cout << a + 1 << " " << b + 1 << "\n";
}