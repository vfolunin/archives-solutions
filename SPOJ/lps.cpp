#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> oddPalindromeCount(string &s) {
    vector<int> palindromeCount(s.size(), 1);
    int l, r = -1;

    for (int i = 0; i < s.size(); i++) {
        int &p = palindromeCount[i];
        if (i <= r)
            p = min(palindromeCount[l + r - i], r - i);

        while (0 <= i - p && i + p < s.size() && s[i - p] == s[i + p])
            p++;

        if (i + p - 1 > r) {
            l = i - p + 1;
            r = i + p - 1;
        }
    }

    return palindromeCount;
}

vector<int> evenPalindromeCount(string &s) {
    vector<int> palindromeCount(s.size());
    int l, r = -1;

    for (int i = 0; i < s.size(); i++) {
        int &p = palindromeCount[i];
        if (i <= r)
            p = min(palindromeCount[l + r - i + 1], r - i + 1);

        while (0 <= i - p - 1 && i + p < s.size() && s[i - p - 1] == s[i + p])
            p++;

        if (i + p - 1 > r) {
            l = i - p;
            r = i + p - 1;
        }
    }

    return palindromeCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s >> s;

    int res = 0;
    for (int count : oddPalindromeCount(s))
        res = max(res, count * 2 - 1);
    for (int count : evenPalindromeCount(s))
        res = max(res, count * 2);

    cout << res;
}