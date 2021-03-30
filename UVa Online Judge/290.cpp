#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string sum(const string &a, const string &b, int base) {
    string res;
    int over = 0;
    for (int ai = a.size() - 1, bi = b.size() - 1; ai >= 0 || bi >= 0 || over; ai--, bi--) {
        static string digits = "0123456789ABCDEF";
        int ad = (ai >= 0 ? digits.find(a[ai]) : 0);
        int bd = (bi >= 0 ? digits.find(b[bi]) : 0);
        int sum = ad + bd + over;
        over = sum / base;
        res += digits[sum % base];
    }
    reverse(res.begin(), res.end());
    return res;
}

bool isPalindrome(const string &s) {
    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

int steps(const string &s, int base) {
    if (isPalindrome(s))
        return 0;
    string r = s;
    reverse(r.begin(), r.end());
    return 1 + steps(sum(s, r, base), base);
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    static string digits = "0123456789ABCDEF";
    int minBase = digits.find(*max_element(s.begin(), s.end())) + 1;

    for (int base = 15; base >= 2; base--) {
        if (base >= minBase)
            cout << steps(s, base);
        else
            cout << "?";
        cout << (base - 1 >= 2 ? " " : "\n");
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}