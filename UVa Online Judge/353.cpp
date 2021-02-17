#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(string &s, int l, int r) {
    while (l < r)
        if (s[l++] != s[r--])
            return 0;
    return 1;
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    set<string> palingromes;
    for (int l = 0; l < s.size(); l++)
        for (int r = l; r < s.size(); r++)
            if (isPalindrome(s, l, r))
                palingromes.insert(s.substr(l, r - l + 1));

    cout << "The string '" << s << "' contains " << palingromes.size() << " palindromes.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}