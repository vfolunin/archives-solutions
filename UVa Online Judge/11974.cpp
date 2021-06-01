#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<int> &masks, int bitCount) {
    vector<int> dist(1 << bitCount, -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int mask : masks) {
            if (dist[v ^ mask] == -1) {
                dist[v ^ mask] = dist[v] + 1;
                q.push(v ^ mask);
            }
        }
    }

    return dist.back();
}

void solve(int test) {
    int bitCount, maskCount;
    cin >> bitCount >> maskCount;

    vector<int> masks(maskCount);
    for (int &mask : masks) {
        for (int bit = 0; bit < bitCount; bit++) {
            int x;
            cin >> x;
            mask |= (x << bit);
        }
    }

    int res = bfs(masks, bitCount);

    cout << "Case " << test << ": ";
    if (res != -1)
        cout << res << "\n";
    else
        cout << "IMPOSSIBLE\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}