#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int planetCount;
    if (!(cin >> planetCount))
        return 0;

    vector<int> a(planetCount), b(planetCount), count(360);
    for (int i = 0; i < planetCount; i++) {
        cin >> a[i] >> a[i] >> b[i];
        a[i] = (a[i] % 360 + 360) % 360;
        b[i] = (b[i] % 360 + 360) % 360;
        count[a[i]]++;
    }

    for (int t = 0; t < 360; t++) {
        if (*max_element(count.begin(), count.end()) > 1) {
            cout << t << "\n";
            return 1;
        }
        for (int i = 0; i < planetCount; i++) {
            count[a[i]]--;
            a[i] = (a[i] + b[i]) % 360;
            count[a[i]]++;
        }
    }

    cout << "GIANIK IS NEVER ECLIPSED\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}