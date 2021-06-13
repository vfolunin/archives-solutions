#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int groupCount;
    cin >> groupCount;

    if (!groupCount)
        return 0;

    vector<int> diffSum(1001);
    for (int i = 0; i < groupCount; i++) {
        int groupSize;
        cin >> groupSize;

        vector<int> group(groupSize);
        for (int &x : group)
            cin >> x;
        sort(group.begin(), group.end());

        for (int t = 0; t <= 1000; t++) {
            int part = upper_bound(group.begin(), group.end(), t) - group.begin();
            diffSum[t] += abs(part - (groupSize - part));
        }
    }

    cout << *min_element(diffSum.begin(), diffSum.end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}