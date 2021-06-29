#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long vertexCount, long long edgeCount, long long bridgeCount) {
    vertexCount -= bridgeCount;
    edgeCount -= bridgeCount;
    return edgeCount <= vertexCount * (vertexCount - 1) / 2;
}

void solve() {
    long long vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    long long l = -1, r = vertexCount;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(vertexCount, edgeCount, m))
            l = m;
        else
            r = m;
    }

    cout << l << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}