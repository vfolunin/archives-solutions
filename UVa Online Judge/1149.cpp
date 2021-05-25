#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n, limit;
    cin >> n >> limit;

    vector<int> a(n);
    for (int &value : a)
        cin >> value;
    sort(a.begin(), a.end());

    int res = 0;
    for (int l = 0, r = n - 1; l <= r; l++, r--) {
        while (l < r && a[l] + a[r] > limit) {
            res++;
            r--;
        }
        res++;
    }

    if (test)
        cout << "\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}