#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, weight;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<Edge> edges;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int weight;
            cin >> weight;

            if (weight != -1)
                edges.push_back({ a, b, weight });
        }
    }

    cout << edges.size() << "\n";
    for (auto &[a, b, weight] : edges)
        cout << a + 1 << " " << b + 1 << " " << weight << "\n";
}