#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> a(7);
    for (int &value : a)
        cin >> value;

    int res = -1e9;
    for (int i = 0; i < a.size(); i++) {
        int sum = 0;
        for (int j = 0; j < a.size(); j++)
            sum += a[j] * (i == j ? 1 : -1);
        res = max(res, sum);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}