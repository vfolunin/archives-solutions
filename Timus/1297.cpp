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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (int len = s.size(); 1; len--) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (isPalindrome(s, l, r)) {
                cout << s.substr(l, len);
                return 0;
            }
        }
    }
}