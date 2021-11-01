#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int guestCount, l, r;
    if (!(cin >> guestCount >> l >> r))
        return 0;

    int allowedGuestCount = 0;
    for (int i = 0; i < guestCount; i++) {
        int guestHeight;
        cin >> guestHeight;
        allowedGuestCount += l <= guestHeight && guestHeight <= r;
    }

    cout << allowedGuestCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}