#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int res = 0;
    for (int i = 0; i < n; i++)
        res += a[(i + n - 1) % n] < a[i] && a[i] > a[(i + 1) % n] ||
               a[(i + n - 1) % n] > a[i] && a[i] < a[(i + 1) % n];

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}