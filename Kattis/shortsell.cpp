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
    long long penalty;
    cin >> size >> penalty;

    vector<long long> a(size);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        a[i] = a[i] * 100 + penalty * i;
    }

    long long res = 0, minValue = 1e18;
    for (int i = a.size() - 1; i >= 0; i--) {
        res = max(res, a[i] - minValue - penalty);
        minValue = min(minValue, a[i]);
    }

    cout << res;
}