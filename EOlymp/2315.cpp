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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = 0; i < queryCount; i++) {
        int l, r, valueL, valueR;
        cin >> l >> r >> valueL >> valueR;
        l--;
        r--;

        int res = 0;
        for (int j = l; j <= r; j++)
            res += valueL <= a[j] && a[j] <= valueR;

        cout << res << "\n";
    }
}