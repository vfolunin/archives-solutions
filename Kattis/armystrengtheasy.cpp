#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int aSize, bSize;
    cin >> aSize >> bSize;

    int aMax = 0;
    for (int i = 0; i < aSize; i++) {
        int a;
        cin >> a;
        aMax = max(aMax, a);
    }

    int bMax = 0;
    for (int i = 0; i < bSize; i++) {
        int b;
        cin >> b;
        bMax = max(bMax, b);
    }

    if (aMax >= bMax)
        cout << "Godzilla\n";
    else
        cout << "MechaGodzilla\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}