#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(string &s) {
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

    for (int i = 0; i < s.size(); i++) {
        if (isPalindrome(s)) {
            cout << "yes";
            return 0;
        }
        rotate(s.begin(), s.begin() + 1, s.end());
    }

    cout << "no";
}