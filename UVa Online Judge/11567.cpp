#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(long long n) {
    if (n <= 1)
        return n;
    if (n % 2 == 0)
        return rec(n / 2) + 1;
    return min(rec(n / 2), rec(n / 2 + 1)) + 2;
}

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    cout << rec(n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}