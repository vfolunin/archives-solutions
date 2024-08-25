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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    bool found = 0;
    for (string s; cin >> s; ) {
        if (s.size() >= 5 && s.size() % 2 && isPalindrome(s + s[0])) {
            cout << s.substr(0, (s.size() + 1) / 2) << " ";
            found = 1;
        }
    }

    if (!found)
        cout << -1;
}