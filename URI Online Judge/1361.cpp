#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x > 0)
            a.push_back(x);
        else
            b.push_back(-x);
    }

    if (a.empty() || b.empty()) {
        cout << (a.empty() && b.empty() ? "0\n" : "1\n");
        return;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a[0] > b[0])
        a.swap(b);

    int res = 0, last = -1;
    while (1) {
        auto it = upper_bound(a.begin(), a.end(), last);
        if (it == a.end())
            break;
        last = *it;
        res++;

        it = upper_bound(b.begin(), b.end(), last);
        if (it == b.end())
            break;
        last = *it;
        res++;
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