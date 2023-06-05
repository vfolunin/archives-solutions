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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    long long product = 1LL * a.front() * a.back();
    for (int l = 0, r = a.size() - 1; l < r; l++, r--) {
        if (1LL * a[l] * a[r] != product) {
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