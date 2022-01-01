#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> a(6);
    for (int &x : a)
        cin >> x;

    if (a[0] + a[5] != 7 || a[1] + a[3] != 7 || a[2] + a[4] != 7) {
        cout << "NAO\n";
        return;
    }

    sort(a.begin(), a.end());

    if (a == vector<int> { 1, 2, 3, 4, 5, 6 })
        cout << "SIM\n";
    else
        cout << "NAO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}