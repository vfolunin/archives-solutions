#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int segmentCount;
    cin >> segmentCount;

    if (!segmentCount)
        return 0;

    vector<pair<int, int>> segments(segmentCount);
    vector<int> ls, rs;

    for (auto &[l, r] : segments) {
        cin >> l >> r;
        ls.push_back(l);
        rs.push_back(r);
    }

    sort(ls.begin(), ls.end());
    sort(rs.begin(), rs.end());

    cout << "Case " << test << ": ";
    for (auto &[l, r] : segments)
        cout << (upper_bound(ls.begin(), ls.end(), r) - ls.begin()) -
                (lower_bound(rs.begin(), rs.end(), l) - rs.begin()) - 1  << " ";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}