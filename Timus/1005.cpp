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

    int res = 1e9;
    for (int mask = 0; mask < (1 << a.size()); mask++) {
        int sum = 0;
        for (int bit = 0; bit < a.size(); bit++)
            sum += (mask & (1 << bit) ? a[bit] : -a[bit]);
        res = min(res, abs(sum));
    }

    cout << res;
}