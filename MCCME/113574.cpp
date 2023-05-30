#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int depth(long long v, int adjCount) {
    if (!v)
        return 0;
    return 1 + depth((v - 1) / adjCount, adjCount);
}

long long lca(long long a, long long b, int adjCount) {
    unordered_set<long long> seen;
    while (1) {
        seen.insert(a);
        if (!a)
            break;
        a = (a - 1) / adjCount;
    }

    while (!seen.count(b))
        b = (b - 1) / adjCount;
    return b;
}

int pathSize(long long a, long long b, int adjCount) {
    return depth(a, adjCount) + depth(b, adjCount) - 2 * depth(lca(a, b, adjCount), adjCount);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long vertexCount;
    int adjCount, queryCount;
    cin >> vertexCount >> adjCount >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        long long a, b;
        cin >> a >> b;
        cout << pathSize(a - 1, b - 1, adjCount) << "\n";
    }
}