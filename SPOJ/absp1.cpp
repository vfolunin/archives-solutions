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
    long long sum = 0;
    for (long long &x : a) {
        cin >> x;
        sum += x;
    }

    sort(a.begin(), a.end());

    long long res = 0;
    for (int i = 0; i < size; i++) {
        sum -= a[i];
        res += sum - a[i] * (size - 1 - i);
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