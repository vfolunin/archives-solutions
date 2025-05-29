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

    int size;
    cin >> size;

    vector<pair<int, int>> pairs(size);
    for (auto &[bonus, cooldown] : pairs)
        cin >> bonus >> cooldown;

    vector<int> res(pairs.size());
    for (int i = res.size() - 1; i >= 0; i--) {
        res[i] = pairs[i].first;
        if (i + pairs[i].second + 1 < res.size())
            res[i] += res[i + pairs[i].second + 1];

        if (i + 1 < pairs.size())
            res[i] = max(res[i], res[i + 1]);
    }

    cout << res[0];
}