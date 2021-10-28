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

    vector<int> a(n);
    int sum = 0;
    for (int &x : a) {
        cin >> x;
        sum += x;
    }

    double res = 0;
    for (int x : a)
        res += x * n > sum;

    cout.precision(3);
    cout << fixed << res / n * 100 << "%\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}