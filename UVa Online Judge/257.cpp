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

bool solve() {
    string word;
    if (!(cin >> word))
        return 0;

    set<string> palindromes;
    for (int len = 3; len <= 4; len++) {
        for (int l = 0, r = len - 1; r < word.size(); l++, r++) {
            if (isPalindrome(word, l, r)) {
                string palindrome = word.substr(l, len);

                if (!palindromes.empty()) {
                    bool ok = 1;
                    for (const string &p : palindromes) {
                        if (palindrome.find(p) != -1) {
                            ok = 0;
                            break;
                        }
                    }

                    if (ok) {
                        cout << word << "\n";
                        return 1;
                    }
                }

                palindromes.insert(palindrome);
            }
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}