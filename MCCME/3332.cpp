#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prefixFunction(string &s) {
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border && s[border] != s[i])
            border = p[border - 1];
        p[i] = border + (s[border] == s[i]);
    }
    return p;
}

int getBorder(string &s, vector<int> &p, int len, int letter) {
    static vector<vector<int>> memo(1e5, vector<int>(26, -1));
    if (memo[len][letter] != -1)
        return memo[len][letter];

    if (len == 0)
        return memo[len][letter] = (s[len] == 'a' + letter);
    else if (s[len] == 'a' + letter)
        return memo[len][letter] = len + 1;
    else
        return memo[len][letter] = getBorder(s, p, p[len - 1], letter);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, alphabetSize, actionCount;
    string s;
    cin >> size >> alphabetSize >> actionCount >> s;

    vector<int> p = prefixFunction(s);
    long long maxBack = 0;

    for (int lettersTyped = 0; lettersTyped < size; lettersTyped++) {
        for (int nextLetter = 0; nextLetter < alphabetSize; nextLetter++) {
            int border = getBorder(s, p, lettersTyped, nextLetter);
            maxBack = max<long long>(maxBack, lettersTyped - border);
        }
    }

    cout << maxBack * actionCount + size;
}