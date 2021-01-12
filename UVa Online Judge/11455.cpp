#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);

    if (a[0] == a[3])
        cout << "square\n";
    else if (a[0] == a[1] && a[2] == a[3])
        cout << "rectangle\n";
    else if (a[0] + a[1] + a[2] > a[3])
        cout << "quadrangle\n";
    else
        cout << "banana\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}