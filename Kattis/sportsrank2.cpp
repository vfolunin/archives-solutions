#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    vector<pair<int, int>> counts(count.begin(), count.end());
    sort(counts.rbegin(), counts.rend());

    int res = 0, totalCount = 0;
    for (int i = 0; i < counts.size(); i++) {
        int rankA = 1 + totalCount;
        int rankB = 1 + i;

        if (rankA > rankB)
            res += counts[i].second;

        totalCount += counts[i].second;
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