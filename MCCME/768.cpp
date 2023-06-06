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

    int segmentCount;
    cin >> segmentCount;

    map<int, int> deltas;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        deltas[l]++;
        deltas[r + 1]--;
    }

    int from, segments = 0;
    long long res = 0;

    for (auto &[coord, delta] : deltas) {
        if (!delta)
            continue;

        if (!segments)
            from = coord;

        segments += delta;

        if (!segments)
            res += coord - from;
    }

    cout << res;
}
