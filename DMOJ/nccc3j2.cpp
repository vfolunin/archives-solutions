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

    for (int i = 0; i + 1 < s.size(); i++) {
        if (isPalindrome(s, 0, i) && isPalindrome(s, i + 1, s.size() - 1)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}