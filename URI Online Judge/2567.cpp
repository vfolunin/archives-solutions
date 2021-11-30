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

    sort(a.begin(), a.end());

    int res = 0;
    for (int l = 0, r = size - 1; l < r; l++, r--)
        res += a[r] - a[l];

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}