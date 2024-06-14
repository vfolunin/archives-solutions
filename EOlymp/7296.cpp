#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> a(12);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    cout << (a[0] == a[3] && a[4] == a[7] && a[8] == a[11] ? "yes\n" : "no\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}