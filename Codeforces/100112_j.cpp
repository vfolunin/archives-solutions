#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;
    vertexCount++;

    vector<int> parent(vertexCount), need(vertexCount), capacity(vertexCount);
    for (int v = 1; v < vertexCount; v++)
        cin >> parent[v] >> need[v] >> capacity[v];

    vector<int> order(vertexCount);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int l, int r) {
        return need[l] < need[r];
    });

    int res = 0;
    for (int v : order) {
        if (!v)
            continue;

        int bottleneck = 1e9;
        for (int curV = v; curV; curV = parent[curV])
            bottleneck = min(bottleneck, capacity[curV]);

        if (need[v] <= bottleneck) {
            res++;
            for (int curV = v; curV; curV = parent[curV])
                capacity[curV] -= need[v];
        }
    }

    cout << res;
}