#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r, mod;
    cin >> l >> r >> mod;

    long long badL = (l / mod + 1) * mod;
    long long badR = (r / mod) * mod;

    if (r < badL) {
        cout << (r - l + 1) / 2;
        return 0;
    }

    long long res = 0;
    res += (badL - l) / 2 + 1;
    res += ((badR - badL) / mod) * ((mod + 1) / 2);
    res += (r - badR) / 2;

    cout << res;
}