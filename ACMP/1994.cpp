#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long toDec(string s, int base) {
    static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long long res = 0;
    for (char c : s)
        res = res * base + DIGITS.find(c);
    return res;
}

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

int transform(int value) {
    string s = fromDec(value, 2);
    s += fromDec(value % 4, 2);
    return toDec(s, 2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int width;
    cin >> width;

    vector<int> a;
    for (int i = 1; i <= 1e5; i++)
        a.push_back(transform(i));

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int res = 0;
    for (int l = 0, r = 0; r < a.size(); r++) {
        while (a[r] - a[l] >= width)
            l++;
        res = max(res, r - l + 1);
    }

    cout << res;
}