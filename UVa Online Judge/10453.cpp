#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    vector<vector<int>> pLen(s.size(), vector<int>(s.size()));
    vector<vector<int>> pType(s.size(), vector<int>(s.size()));
    
    for (int i = 0; i < s.size(); i++)
        pLen[i][i] = 1;

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            if (s[l] == s[r]) {
                pLen[l][r] = pLen[l + 1][r - 1] + 2;
                pType[l][r] = 0;
            } else {
                if (pLen[l + 1][r] <= pLen[l][r - 1]) {
                    pLen[l][r] = pLen[l + 1][r] + 2;
                    pType[l][r] = 1;
                } else {
                    pLen[l][r] = pLen[l][r - 1] + 2;
                    pType[l][r] = 2;
                }
            }
        }
    }

    string palindrome(pLen[0][s.size() - 1], ' ');
    int l = 0, r = s.size() - 1, pl = 0, pr = palindrome.size() - 1;
    while (l < r) {
        if (pType[l][r] == 0) {
            palindrome[pl++] = s[l++];
            palindrome[pr--] = s[r--];
        } else if (pType[l][r] == 1) {
            palindrome[pl++] = s[l];
            palindrome[pr--] = s[l++];
        } else {
            palindrome[pl++] = s[r];
            palindrome[pr--] = s[r--];
        }
    }
    palindrome[pl] = s[l];

    cout << palindrome.size() - s.size() << " " << palindrome << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}