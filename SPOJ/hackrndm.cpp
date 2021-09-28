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

    int size, diff;
    cin >> size >> diff;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    long long res = 0;
    for (int x : a) {
        auto [l, r] = equal_range(a.begin(), a.end(), x + diff);
        res += r - l;
    }

    cout << res;
}