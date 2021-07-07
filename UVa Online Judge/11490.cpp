#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e8 + 7;

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    bool found = 0;
    for (long long border = 1; 6 * border * border < n; border++) {
        long long num = n - 6 * border * border;
        long long den = 7 * border;
        if (num % den)
            continue;

        found = 1;
        long long side = num / den % MOD;
        cout << "Possible Missing Soldiers = " << 2 * side * side % MOD << "\n";
    }

    if (!found)
        cout << "No Solution Possible\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}