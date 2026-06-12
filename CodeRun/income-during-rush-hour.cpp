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

    int size, limit;
    cin >> size >> limit;

    vector<pair<int, int>> pairs(size);
    for (auto &[time, value] : pairs)
        cin >> time >> value;

    sort(pairs.begin(), pairs.end());

    int cur = 0, res = 0;
    for (int l = 0, r = 0; r < pairs.size(); r++) {
        cur += pairs[r].second;
        while (pairs[l].first + limit <= pairs[r].first) {
            cur -= pairs[l].second;
            l++;
        }
        res = max(res, cur);
    }

    cout << res;
}