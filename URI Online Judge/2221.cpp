#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int bonus;
    int a1, d1, l1, a2, d2, l2;
    cin >> bonus >> a1 >> d1 >> l1 >> a2 >> d2 >> l2;

    int val1 = a1 + d1 + (l1 % 2 ? 0 : 2 * bonus);
    int val2 = a2 + d2 + (l2 % 2 ? 0 : 2 * bonus);

    if (val1 < val2)
        cout << "Guarte\n";
    else if (val1 == val2)
        cout << "Empate\n";
    else
        cout << "Dabriel\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}