#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string fromDec(long long n, int base) {
    static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    while (n >= base) {
        res += DIGITS[n % base];
        n /= base;
    }
    res += DIGITS[n];
    reverse(res.begin(), res.end());
    return res;
}

bool isPalindrome(const string &s) {
    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> bases;
    for (int base = 2; base <= 36; base++)
        if (isPalindrome(fromDec(n, base)))
            bases.push_back(base);

    if (bases.empty())
        cout << "none";
    else if (bases.size() == 1)
        cout << "unique\n";
    else
        cout << "multiple\n";

    for (int base : bases)
        cout << base << " ";
}