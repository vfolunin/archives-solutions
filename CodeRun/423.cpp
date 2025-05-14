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
        int value;
        cin >> value;

        int r = lower_bound(a.begin(), a.end(), value) - a.begin();
        int l = r - 1;

        if (r == a.size() || 0 <= l && value - a[l] <= a[r] - value)
            cout << l + 1 << "\n";
        else
            cout << r + 1 << "\n";
    }
}