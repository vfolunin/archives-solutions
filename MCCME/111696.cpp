#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toLower(string &s) {
    string res;
    for (char c : s)
        if (isalpha(c))
            res += tolower(c);
    return res;
}

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
    getline(cin, s);

    s = toLower(s);
    int l = 0, r = s.size() - 1;
    while (l < r && s[l] == s[r]) {
        l++;
        r--;
    }

    if (l >= r) {
        cout << "YES\n" << s;
        return 0;
    }

    vector<string> candidates(3, s);
    candidates[0].erase(l, 1);
    candidates[1].erase(r, 1);
    candidates[2][l] = candidates[2][r];

    for (string &candidate : candidates) {
        if (isPalindrome(candidate)) {
            cout << "YES\n" << candidate;
            return 0;
        }
    }

    cout << "NO";
}