#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int mask, vector<int> &cover, vector<int> &memo) {
    int &res = memo[mask];
    if (res != -1)
        return res;

    res = 0;
    for (int subMask = mask; subMask; subMask = (subMask - 1) & mask)
        if (cover[subMask])
            res = max(res, 1 + rec(mask ^ subMask, cover, memo));
    return res;
}

bool solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> degree;
        graph[v].resize(degree);
        for (int &to : graph[v])
            cin >> to;
    }

    vector<int> cover(1 << vertexCount);
    for (int mask = 0; mask < (1 << vertexCount); mask++) {
        int affectedMask = mask;
        for (int v = 0; v < vertexCount; v++)
            if (mask & (1 << v))
                for (int to : graph[v])
                    affectedMask |= 1 << to;

        if (affectedMask == (1 << vertexCount) - 1)
            cover[mask] = 1;
    }

    vector<int> memo(1 << vertexCount, -1);
    int res = rec((1 << vertexCount) - 1, cover, memo);

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}