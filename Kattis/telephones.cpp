#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int callCount, queryCount;
    cin >> callCount >> queryCount;

    if (!callCount && !queryCount)
        return 0;

    vector<pair<int, int>> call(callCount);
    for (auto &[l, r] : call) {
        cin >> l >> l >> l >> r;
        r += l;
    }

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        r += l;

        int res = 0;
        for (auto &[cl, cr] : call)
            res += cl < r && l < cr;

        cout << res << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}