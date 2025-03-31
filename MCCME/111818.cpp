#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, weight, index;

    bool operator < (const Edge &that) const {
        return weight < that.weight;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (int i = 0; i < edges.size(); i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].weight;
        edges[i].index = i + 1;
    }

    sort(edges.begin(), edges.end());

    for (auto &[a, b, weight, index] : edges)
        cout << a << " " << b << " " << weight << " " << index << "\n";
}