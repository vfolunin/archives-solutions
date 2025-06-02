#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, count;
    cin >> size >> count;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    string mask = string(size - count, '0') + string(count, '1');
    int res = 0;
    do {
        int cur = 0;
        for (int i = 0; i < mask.size(); i++)
            if (mask[i] == '1')
                cur ^= a[i];
        res = max(res, cur);
    } while (next_permutation(mask.begin(), mask.end()));

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}