#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, pred;
    cin >> size >> pred;

    int mode = 0, res = 1;

    for (int i = 1; i < size; i++) {
        int cur;
        cin >> cur;

        if (cur == pred)
            continue;

        if (mode == 0 && pred > cur || mode == 1 && pred < cur) {
            res++;
            mode ^= 1;
        }

        pred = cur;
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