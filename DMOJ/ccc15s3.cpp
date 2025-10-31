#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int m) {
    set<int> values;
    for (int value = 0; value < m; value++)
        values.insert(value);

    for (int i = 0; i < m; i++) {
        auto it = values.upper_bound(a[i]);
        if (it == values.begin())
            return 0;
        values.erase(--it);
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l = 0, r, size;
    cin >> r >> size;
    r++;

    vector<int> a(size);
    for (int &value : a) {
        cin >> value;
        value--;
    }

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, m))
            l = m;
        else
            r = m;
    }

    cout << l;
}