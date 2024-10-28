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

    int size, width;
    cin >> size >> width;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    long long res = 1e18;
    for (int l = 0, r = width - 1; r < a.size(); l++, r++)
        res = min(res, a[r] - a[l]);

    cout << res;
}