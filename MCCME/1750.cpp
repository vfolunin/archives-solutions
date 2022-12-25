#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> oddPalindromeCount(string &s) {
    vector<int> palindromeCount(s.size(), 1);
    int l, r = -1;

    for (int i = 0; i < s.size(); i++) {
        int &p = palindromeCount[i];
        if (i <= r)
            p = min(palindromeCount[l + r - i], r - i);

        while (0 <= i - p && i + p < s.size() && s[i - p] == s[i + p])
            p++;

        if (i + p - 1 > r) {
            l = i - p + 1;
            r = i + p - 1;
        }
    }

    return palindromeCount;
}

vector<vector<int>> manacher(string &s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }

    vector<int> palindromeCount = oddPalindromeCount(t);

    vector<vector<int>> res(2);
    for (int i = 0; i + 1 < palindromeCount.size(); i++)
        res[i % 2].push_back(palindromeCount[i] / 2);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<vector<int>> values = manacher(s);
    long long palindromeCount = 0;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < s.size(); j++)
            palindromeCount += values[i][j];

    cout << palindromeCount;

}