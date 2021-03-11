#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long sum;
    cin >> sum;

    if (!sum)
        return 0;

    long long l = 1, r = 1e9;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (m * (m + 1) / 2 > sum)
            r = m;
        else
            l = m;
    }

    cout << r * (r + 1) / 2 - sum << " " << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}