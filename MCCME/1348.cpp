#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int w;
    vector<int> a, b;

    friend istream &operator >> (istream &in, Edge &edge) {
        in >> edge.w;

        int aSize;
        in >> aSize;

        edge.a.resize(aSize);
        for (int &v : edge.a) {
            in >> v;
            v--;
        }

        int bSize;
        in >> bSize;

        edge.b.resize(bSize);
        for (int &v : edge.b) {
            in >> v;
            v--;
        }

        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, startCount, finish;
    cin >> vertexCount >> edgeCount >> startCount >> finish;
    finish--;

    vector<Edge> edges(edgeCount);
    for (Edge &edge : edges)
        cin >> edge;

    vector<int> dist(vertexCount, 1e9);
    fill(dist.begin(), dist.begin() + startCount, 0);

    for (int i = 0; i < vertexCount - 1; i++) {
        for (Edge &edge : edges) {
            int distA = 0;
            for (int v : edge.a)
                distA = max(distA, dist[v]);

            for (int v : edge.b)
                dist[v] = min(dist[v], distA + edge.w);
        }
    }

    cout << (dist[finish] != 1e9 ? dist[finish] : -1);
}