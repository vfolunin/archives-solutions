#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool canBeNext(int size, int maskA, int maskB) {
    if (maskA & maskB)
        return 0;

    int mask = maskA | maskB, zeroRow = 0;
    for (int bit = 0; bit < size; bit++) {
        if (!(mask & (1 << bit)))
            zeroRow++;
        else if (zeroRow % 2 == 0)
            zeroRow = 0;
        else
            return 0;
    }
    return zeroRow % 2 == 0;
}

vector<vector<int>> prepareNextGraph(int size) {
    vector<vector<int>> graph(1 << size);
    for (int maskA = 0; maskA < (1 << size); maskA++)
        for (int maskB = 0; maskB < (1 << size); maskB++)
            if (canBeNext(size, maskA, maskB))
                graph[maskA].push_back(maskB);
    return graph;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    const long long MOD = 1e9 + 7;
    vector<vector<int>> ways(w + 1, vector<int>(1 << h));
    ways[0][0] = 1;

    vector<vector<int>> nextGraph = prepareNextGraph(h);

    for (int size = 0; size < w; size++)
        for (int mask = 0; mask < (1 << h); mask++)
            for (int nextMask : nextGraph[mask])
                ways[size + 1][nextMask] = (ways[size + 1][nextMask] + ways[size][mask]) % MOD;

    cout << ways[w][0];
}