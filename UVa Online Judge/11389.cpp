#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, limit, cost;
    cin >> n >> limit >> cost;

    if (!n && !limit && !cost)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    vector<int> b(n);
    for (int &x : b)
        cin >> x;
    sort(b.rbegin(), b.rend());

    long long res = 0;
    for (int i = 0; i < n; i++)
        res += max<long long>(a[i] + b[i] - limit, 0) * cost;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}