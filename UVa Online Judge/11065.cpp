#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> rec(int from, int vertexCount, long long usedMask, vector<long long> &adjMask, int depth) {
    if (usedMask == (1LL << vertexCount) - 1)
        return { 1, depth };
    
    int independentSetCount = 0, maxIndependentSetSize = 0;

    for (int v = from; v < vertexCount; v++) {
        if (!(usedMask & (1LL << v))) {
            auto [count, size] = rec(v + 1, vertexCount, usedMask | (1LL << v) | adjMask[v], adjMask, depth + 1);
            independentSetCount += count;
            maxIndependentSetSize = max(maxIndependentSetSize, size);
        }
    }

    return { independentSetCount, maxIndependentSetSize };
}

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<long long> adjMask(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        adjMask[a] |= 1LL << b;
        adjMask[b] |= 1LL << a;
    }

    auto [independentSetCount, maxIndependentSetSize] = rec(0, vertexCount, 0, adjMask, 0);

    cout << independentSetCount << "\n";
    cout << maxIndependentSetSize << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}