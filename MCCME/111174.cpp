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
 
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int l, r, delta;
    cin >> l >> r >> delta;

    l = (l - 1) / delta;
    r = (r - 1) / delta;

    if (r - l + 1 >= size) {
        cout << *max_element(a.begin(), a.end());
        return 0;
    }

    int res = a[l % size];
    for (int i = l; i <= r; i++)
        res = max(res, a[i % size]);

    reverse(a.begin() + 1, a.end());
    for (int i = l; i <= r; i++)
        res = max(res, a[i % size]);

    cout << res;
}