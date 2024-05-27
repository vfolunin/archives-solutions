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

    int size, limit;
    cin >> size >> limit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int res = -1;
    for (int l = 0, r = a.size() - 1; l < r; l++) {
        while (l < r && a[l] + a[r] > limit)
            r--;
        if (l < r)
            res = max(res, a[l] + a[r]);
    }

    cout << res;
}