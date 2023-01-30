#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(const string &s) {
    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

bool isPrime(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    bool found = 0;
    for (int i = l; i <= r; i++) {
        if (isPalindrome(to_string(i)) && isPrime(i)) {
            cout << i << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}