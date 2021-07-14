#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<pair<int, int>> &segments, vector<int> &p, int dist) {
    int x = segments[p[0]].first;
    for (int i = 1; i < p.size(); i++) {
        auto &[l, r] = segments[p[i]];
        if (x + dist <= r)
            x = max(x + dist, l);
        else
            return 0;
    }
    return 1;
}

bool solve(int test) {
    int segmentCount;
    cin >> segmentCount;

    if (!segmentCount)
        return 0;

    vector<pair<int, int>> segments(segmentCount);
    for (auto &[l, r] : segments) {
        cin >> l >> r;
        l *= 600;
        r *= 600;
    }

    vector<int> p(segmentCount);
    for (int i = 0; i < segmentCount; i++)
        p[i] = i;

    int res = 0;
    do {
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(segments, p, m))
                l = m;
            else
                r = m;
        }
        res = max(res, l);
    } while (next_permutation(p.begin(), p.end()));

    cout << "Case " << test << ": ";
    cout << res / 600 << ":";
    cout << setw(2) << setfill('0') << (res % 600 + 5) / 10 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}