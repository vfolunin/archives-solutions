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

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            res += l <= a[i] + a[j] && a[i] + a[j] <= r;

    cout << res << "\n";
}