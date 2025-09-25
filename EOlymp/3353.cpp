#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    long long l = 0, r = 1e4;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (m * (m + 1) / 2 < n)
            l = m;
        else
            r = m;
    }

    long long diag = r, diagPos = (diag * (diag + 1) / 2) - n;
    if (diag % 2)
        cout << "TERM " << n << " IS " << diagPos + 1 << "/" << diag - diagPos << "\n";
    else
        cout << "TERM " << n << " IS " << diag - diagPos << "/" << diagPos + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}