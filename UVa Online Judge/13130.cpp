#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> a(5);
    for (int &x : a)
        cin >> x;

    bool increasing = 1;
    for (int i = 1; i < 5; i++)
        increasing &= a[i - 1] + 1 == a[i];

    cout << (increasing ? "Y\n" : "N\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}