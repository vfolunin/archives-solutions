#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> oddPalindromeCount(string &s) {
    vector<int> palindromeCount(s.size());
    int l = 0, r = -1;

    for (int i = 0; i < s.size(); i++) {
        int &p = palindromeCount[i];
        if (i > r)
            p = 1;
        else
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (int value : oddPalindromeCount(s))
        cout << value * 2 - 1 << " ";
}