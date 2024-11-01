#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

void solve() {
    vector<pair<int, int>> events;
    while (1) {
        int l, r;
        cin >> l >> r;

        if (!l && !r)
            break;

        events.emplace_back(l, r);
    }

    sort(events.begin(), events.end(), compare);

    int res = 0, last = -1;
    for (auto &[l, r] : events) {
        if (last <= l) {
            last = r;
            res++;
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}