#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

void solve() {
    int dollCount;
    cin >> dollCount;

    vector<pair<int, int>> dolls(dollCount);
    for (auto &[h, w] : dolls)
        cin >> h >> w;

    sort(dolls.begin(), dolls.end(), compare);
    vector<int> widths(dollCount);
    for (int i = 0; i < dollCount; i++)
        widths[i] = dolls[i].second;

    vector<int> last(dollCount + 1, 1e9);
    last[0] = 0;
    for (int w : widths)
        *upper_bound(last.begin(), last.end(), w) = w;

    int res = dollCount;
    while (last[res] == 1e9)
        res--;

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