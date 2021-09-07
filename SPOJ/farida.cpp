#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    if (!n) {
        cout << "Case " << test << ": 0\n";
        return;
    }

    vector<long long> coinCount(n);
    for (int i = 0; i < n; i++) {
        cin >> coinCount[i];
        long long pred = 0;
        if (i >= 2)
            pred = coinCount[i - 2];
        if (i >= 3)
            pred = max(pred, coinCount[i - 3]);
        coinCount[i] += pred;
    }

    cout << "Case " << test << ": " << *max_element(coinCount.begin(), coinCount.end()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}