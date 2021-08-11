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

    vector<int> k(n);
    for (int &k : k)
        cin >> k;

    int res = 0, kLess = 0;

    for (int i = 0; i < n; i++) {
        while (i && k[i - 1] >= 2 && k[i] >= 1) {
            kLess -= 2;
            k[i - 1] -= 2;
            k[i]--;
            res++;
        }

        while (kLess >= 1 && k[i] >= 2) {
            kLess--;
            k[i] -= 2;
            res++;
        }

        while (k[i] >= 3) {
            k[i] -= 3;
            res++;
        }

        kLess += k[i];
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