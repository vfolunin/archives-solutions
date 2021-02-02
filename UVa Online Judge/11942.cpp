#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> a(10);
    for (int &x : a)
        cin >> x;

    if (is_sorted(a.begin(), a.end()) || is_sorted(a.rbegin(), a.rend()))
        cout << "Ordered\n";
    else
        cout << "Unordered\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << "Lumberjacks:\n";
    for (int i = 0; i < n; i++)
        solve();
}