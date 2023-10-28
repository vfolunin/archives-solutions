#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long sum(long long l, long long r) {
    return (l + r) * (r - l + 1) / 2;
}

long long xDelta(long long h, long long w, int x) {
    long long a = sum(0, h - 1) * w * x + sum(1, x) * h;
    long long b = sum(1, h * w) - a;
    return a - b;
}

long long yDelta(long long h, long long w, int y) {
    long long a = sum(1, y * w);
    long long b = sum(1, h * w) - a;
    return a - b;
}

template<typename F>
pair<int, long long> find(long long h, long long w, int limit, F fDelta) {
    int l = 1, r = limit - 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (fDelta(h, w, m) < 0)
            l = m;
        else
            r = m;
    }
    long long lDelta = abs(fDelta(h, w, l));
    long long rDelta = abs(fDelta(h, w, r));
    return lDelta <= rDelta ? make_pair(l, lDelta) : make_pair(r, rDelta);
}

void solve() {
    int h, w;
    cin >> h >> w;

    char resType = '?';
    int res;
    long long resDelta = 1e18;

    if (w > 1) {
        auto [x, delta] = find(h, w, w, xDelta);
        if (resDelta > delta) {
            resType = 'V';
            res = x + 1;
            resDelta = delta;
        }
    }

    if (h > 1) {
        auto [y, delta] = find(h, w, h, yDelta);
        if (resDelta > delta) {
            resType = 'H';
            res = y + 1;
            resDelta = delta;
        }
    }

    cout << resType << " " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}