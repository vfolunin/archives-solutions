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

    if (vertexCount == 1) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> dist[a][b];

    vector<int> order(vertexCount);
    iota(order.begin(), order.end(), 0);

    int res = -1;
    do {
        int ok = 1, cur = 0;
        for (int i = 0; ok && i < vertexCount; i++) {
            ok &= dist[order[i]][order[(i + 1) % vertexCount]] != 0;
            cur += dist[order[i]][order[(i + 1) % vertexCount]];
        }
        if (ok && (res == -1 || res > cur))
            res = cur;
    } while (next_permutation(order.begin(), order.end()));

    cout << res;
}