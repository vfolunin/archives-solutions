#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int eventCount;
    cin >> eventCount;

    if (eventCount == -1)
        return 0;

    map<int, multimap<int, int>> l, r;
    for (int i = 0; i < eventCount; i++) {
        int type, note, ta, tb, tc;
        cin >> type >> note >> ta >> tb >> tc;

        int t = (ta * 4 + tb - 1) * 480 + tc;
        if (t % 60 < 30)
            t = t / 60 * 60;
        else
            t = (t / 60 + 1) * 60;

        if (type == 1) {
            l[note].insert({ t, i });
        } else {
            if (auto it = l[note].find(t); it != l[note].end())
                l[note].erase(it);
            else
                r[note].insert({ t, i });
        }
    }

    vector<vector<int>> res;
    for (auto &[note, times] : l)
        for (auto &[t, i] : times)
            res.push_back({ t, i, 1, note });
    for (auto &[note, times] : r)
        for (auto &[t, i] : times)
            res.push_back({ t, i, 0, note });
    sort(res.begin(), res.end());

    cout << res.size() << "\n";
    for (vector<int> &r : res) {
        cout << r[2] << " " << r[3] << " ";
        cout << r[0] / 4 / 480 << " " << r[0] % (4 * 480) / 480 + 1 << " " << r[0] % 480 << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
    cout << "-1\n";
}