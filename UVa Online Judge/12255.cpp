#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<pair<long long, long long>> &guards, int sniperCount, long long maxDist, long long sy) {
    long long sx = -1e9;
    int snipersNeed = 0;

    for (auto &[x, y] : guards) {
        long long dx = x - sx;
        long long dy = y - sy;

        if (dy > maxDist)
            return 0;

        if (dx * dx + dy * dy <= maxDist * maxDist)
            continue;

        snipersNeed++;
        sx = x + sqrt(maxDist * maxDist - dy * dy);
    }

    return snipersNeed <= sniperCount;
}

void solve(int test) {
    long long y, maxDist;
    int guardCount, sniperCount;
    cin >> y >> guardCount >> sniperCount >> maxDist;

    vector<pair<long long, long long>> guards(guardCount);
    for (auto &[x, y] : guards)
        cin >> x >> y;
    sort(guards.begin(), guards.end());

    long long l = -1, r = 1e10;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(guards, sniperCount, maxDist, y - m))
            l = m;
        else
            r = m;
    }

    cout << "Case " << test << ": ";
    if (l < 0)
        cout << "IMPOSSIBLE\n";
    else
        cout << l << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}