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

    sort(a.begin(), a.end());

    int res = 1e9;
    for (int l = 0, r = a.size() - 1; l < r; l++, r--)
        res = min(res, a[l] + a[r]);

    cout << res;
}