#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long value, index;
    if (!(cin >> value >> index))
        return 0;

    long long res = 0;
    for (int bit = 0; bit < 63; bit++) {
        if (!(value & (1LL << bit))) {
            res |= (index % 2) << bit;
            index /= 2;
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}