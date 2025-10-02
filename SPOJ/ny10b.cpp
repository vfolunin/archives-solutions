#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> fromDec(int n, int base) {
    vector<int> res;
    while (n >= base) {
        res.push_back(n % base);
        n /= base;
    }
    res.push_back(n);
    reverse(res.begin(), res.end());
    return res;
}

int toDec(vector<int> &digits, int base) {
    int res = 0;
    for (int digit : digits)
        res = res * base + digit;
    return res;
}

int getDigit(vector<int> &digits, int i) {
    if (i < digits.size())
        return digits[digits.size() - 1 - i];
    return 0;
}

void solve() {
    int test, base, a, b;
    cin >> test >> base >> a >> b;

    vector<int> aDigits = fromDec(a, base);
    vector<int> bDigits = fromDec(b, base);

    vector<int> resDigits(max(aDigits.size(), bDigits.size()));
    for (int i = 0; i < resDigits.size(); i++)
        resDigits[i] = (getDigit(aDigits, resDigits.size() - 1 - i) +
                        getDigit(bDigits, resDigits.size() - 1 - i)) % base;

    cout << test << " " << toDec(resDigits, base) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}