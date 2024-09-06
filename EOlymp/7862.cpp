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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int segmentCount, lockTime;
    cin >> segmentCount >> lockTime;

    vector<pair<int, int>> segments(segmentCount);
    for (auto &[l, t] : segments)
        cin >> l >> t;

    sort(segments.begin(), segments.end());

    multiset<int> workstations;
    int res = 0;

    for (auto &[l, t] : segments) {
        while (!workstations.empty() && *workstations.begin() + lockTime < l)
            workstations.erase(workstations.begin());

        if (!workstations.empty() && *workstations.begin() <= l) {
            workstations.erase(workstations.begin());
            res++;
        }

        workstations.insert(l + t);
    }

    cout << res;
}