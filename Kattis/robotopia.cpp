#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a1, b1, a2, b2, a, b;
    cin >> a1 >> b1 >> a2 >> b2 >> a >> b;

    int r1 = -1, r2 = -1;
    for (int k1 = 1; k1 * a1 <= a && k1 * b1 <= b; k1++) {
        int k2 = (a - k1 * a1) / a2;
        if (k2 > 0 && k1 * a1 + k2 * a2 == a && k1 * b1 + k2 * b2 == b) {            
            if (r1 == -1) {
                r1 = k1;
                r2 = k2;
            } else {
                cout << "?\n";
                return;
            }
        }
    }

    if (r1 != -1)
        cout << r1 << " " << r2 << "\n";
    else
        cout << "?\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}