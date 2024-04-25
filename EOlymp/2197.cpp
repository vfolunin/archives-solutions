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

    string s;
    cin >> s;

    if (!isPalindrome(s)) {
        cout << s;
        return 0;
    }

    if (!isPalindrome(s.substr(1))) {
        cout << min(s.substr(1), s.substr(0, s.size() - 1));
        return 0;
    }

    cout << "NO SOLUTION";
}