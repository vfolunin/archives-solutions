#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a1, b1, a2, b2;
    string x;
    cin >> a1 >> x >> b1 >> b2 >> x >> a2;

    int ar = 0, br = 0;

    if (a1 > b1) {
        ar += 3;
    } else if (a1 < b1) {
        br += 3;
    } else {
        ar++;
        br++;
    }

    if (a2 > b2) {
        ar += 3;
    } else if (a2 < b2) {
        br += 3;
    } else {
        ar++;
        br++;
    }

    if (ar != br) {
        cout << "Time " << (ar > br ? 1 : 2) << "\n";
        return;
    }

    ar = a1 + a2 - b1 - b2;
    br = b1 + b2 - a1 - a2;

    if (ar != br) {
        cout << "Time " << (ar > br ? 1 : 2) << "\n";
        return;
    }

    ar = a2;
    br = b1;

    if (ar != br) {
        cout << "Time " << (ar > br ? 1 : 2) << "\n";
        return;
    }

    cout << "Penaltis\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}