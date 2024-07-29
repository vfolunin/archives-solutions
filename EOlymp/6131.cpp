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
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    for (int l = 0, r = a.size() - 1; l < r; l++, r--) {
        if (a[l] * a[r] != a.front() * a.back()) {
            cout << "0\n";
            return;
        }
    }

    cout << "1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}