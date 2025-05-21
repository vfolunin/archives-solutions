#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    int res = 1, cur = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] == a[i])
            cur++;
        else
            cur = 1;
        res = max(res, cur);
    }

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