#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int nameCount;
    cin >> nameCount;

    vector<string> names(nameCount);
    for (string &name : names)
        cin >> name;

    sort(names.begin(), names.end());

    int res = 0, prevLcp = 1;
    for (int i = 1; i < nameCount; i++) {
        int lcp = 0;
        while (lcp < names[i - 1].size() && lcp < names[i].size() && names[i - 1][lcp] == names[i][lcp])
            lcp++;
        lcp++;
        res += max(prevLcp, lcp);
        prevLcp = lcp;
    }
    res += max(prevLcp, 1);

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