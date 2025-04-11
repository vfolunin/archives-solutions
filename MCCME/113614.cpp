#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(string &s, int l, int r) {
    for (; l < r; l++, r--)
        if (s[l] != s[r])
            return 0;
    return 1;
}

int getPalindromeSize(string &s) {
    int res = 1;
    for (int l = 0; l < s.size(); l++)
        for (int r = l; r < s.size(); r++)
            if (isPalindrome(s, l, r))
                res = max(res, r - l + 1);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s >> s;

    int res = getPalindromeSize(s);
    for (char &c : s) {
        char prevC = c;
        for (c = 'a'; c <= 'z'; c++)
            res = max(res, getPalindromeSize(s));
        c = prevC;
    }

    cout << res;
}