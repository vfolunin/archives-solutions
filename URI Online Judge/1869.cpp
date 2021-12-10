#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    unsigned long long n;
    if (!(cin >> n))
        return 0;

    static string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    while (n >= 32) {
        res += digits[n % 32];
        n /= 32;
    }
    res += digits[n];
    reverse(res.begin(), res.end());

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}