#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int segmentCount, threshold;
    cin >> segmentCount >> threshold;

    map<int, int> delta;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        delta[l]++;
        delta[r + 1]--;
    }

    int cur = 0, from, res = 0;
    for (auto &[coord, delta] : delta) {
        if (cur < threshold && cur + delta >= threshold)
            from = coord;
        if (cur >= threshold && cur + delta < threshold)
            res += coord - from - 1;
        cur += delta;
    }

    cout << res;
}