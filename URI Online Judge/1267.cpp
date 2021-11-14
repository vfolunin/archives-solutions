#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int guestCount, dinnerCount;
    cin >> guestCount >> dinnerCount;

    if (!dinnerCount && !guestCount)
        return 0;

    vector<int> guestDinners(guestCount);
    for (int i = 0; i < dinnerCount; i++) {
        for (int j = 0; j < guestCount; j++) {
            int participated;
            cin >> participated;
            guestDinners[j] += participated;
        }
    }

    if (*max_element(guestDinners.begin(), guestDinners.end()) == dinnerCount)
        cout << "yes\n";
    else
        cout << "no\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}