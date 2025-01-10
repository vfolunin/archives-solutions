#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b, mod, value;
    if (!(cin >> a >> b >> mod >> value))
        return 0;

    int andSum = value;
    int orSum = value;

    for (int i = 0; i < mod; i++) {
        value = (a * value + b) % mod;
        andSum &= value;
        orSum |= value;
    }

    for (int bit = 15; bit >= 0; bit--) {
        if ((andSum ^ orSum) & (1 << bit))
            cout << "?";
        else
            cout << ((andSum >> bit) & 1);
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}