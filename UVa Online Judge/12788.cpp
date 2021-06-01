#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    int res = 1;
    for (int l = 0, r = 0, inv = 0; l < size; l++) {
        while (r < size && inv <= 1) {
            inv += r + 1 < size && a[r] > a[r + 1];
            r++;
        }
        res = max(res, r - l);
        inv -= l + 1 < size && a[l] > a[l + 1];
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}