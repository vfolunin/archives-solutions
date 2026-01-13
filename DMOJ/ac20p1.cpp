#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<long long> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());

    if (a[0] * a[0] + a[1] * a[1] < a[2] * a[2])
        cout << "O\n";
    else if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
        cout << "R\n";
    else
        cout << "A\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}