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
    for (int a, b; cin >> a >> b; )
        if (a && b)
            edges.push_back({ a - 1, b - 1 });

    sort(edges.begin(), edges.end());

    vector<long long> ways(vertexCount);
    ways[0] = 1;

    for (auto &[a, b] : edges)
        ways[b] += ways[a];

    cout << ways.back();
}