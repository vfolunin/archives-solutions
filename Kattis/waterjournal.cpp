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

    int size, l, r;
    cin >> size >> l >> r;

    bool lSeen = 0, rSeen = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        lSeen |= value == l;
        rSeen |= value == r;
    }

    if (!lSeen && !rSeen) {
        cout << -1;
    } else if (!lSeen) {
        cout << l;
    } else if (!rSeen) {
        cout << r;
    } else {
        for (int value = l; value <= r; value++)
            cout << value << "\n";
    }
}