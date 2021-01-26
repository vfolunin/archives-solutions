#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int width;
    cin >> width;

    map<int, int> maxFrom;
    while (1) {
        int l, r;
        cin >> l >> r;

        if (!l && !r)
            break;

        if (!maxFrom.count(l))
            maxFrom[l] = r;
        else
            maxFrom[l] = max(maxFrom[l], r);
    }

    map<int, pair<int, int>> maxBefore;
    int ml = -1e9, mr = -1e9;
    for (auto &[l, r] : maxFrom) {
        if (r > mr) {
            ml = l;
            mr = r;
        }
        maxBefore[l] = { ml, mr };
    }

    if (test)
        cout << "\n";

    vector<pair<int, int>> res;
    int last = 0;

    while (1) {
        auto it = maxBefore.upper_bound(last);
        if (it == maxBefore.begin() || (--it)->second.second <= last) {
            cout << "0\n";
            return;
        }

        res.push_back(it->second);
        last = it->second.second;
        if (last >= width)
            break;
    }

    cout << res.size() << "\n";
    for (auto &[l, r] : res)
        cout << l << " " << r << "\n";
    return;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}