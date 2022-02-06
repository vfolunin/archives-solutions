#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int poleLength, antCount;
    cin >> poleLength >> antCount;

    int l = -1, r = -1;
    for (int i = 0; i < antCount; i++) {
        int antX;
        cin >> antX;

        if (antX > poleLength - antX)
            antX = poleLength - antX;

        l = max(l, antX);
        r = max(r, poleLength - antX);
    }

    cout << l << " " << r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}