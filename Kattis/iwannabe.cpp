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

    int itemCount, selectedCount;
    cin >> itemCount >> selectedCount;

    vector<pair<long long, int>> a(itemCount), b(itemCount), c(itemCount);
    for (int i = 0; i < itemCount; i++) {
        cin >> a[i].first >> b[i].first >> c[i].first;
        a[i].second = b[i].second = c[i].second = i;
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    set<int> selected;
    for (int i = 0; i < selectedCount; i++) {
        selected.insert(a[i].second);
        selected.insert(b[i].second);
        selected.insert(c[i].second);
    }

    cout << selected.size();
}