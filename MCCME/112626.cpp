#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool matches(string &pattern, string &word) {
    vector<vector<int>> res(pattern.size() + 1, vector<int>(word.size() + 1));
    res[0][0] = 1;

    for (int patternLen = 1; patternLen <= pattern.size(); patternLen++) {
        for (int wordLen = 0; wordLen <= word.size(); wordLen++) {
            if (pattern[patternLen - 1] == '*') {
                for (int partLen = 0; partLen <= wordLen; partLen++)
                    res[patternLen][wordLen] |= res[patternLen - 1][partLen];
            } else if (wordLen && (pattern[patternLen - 1] == '?' || pattern[patternLen - 1] == word[wordLen - 1])) {
                res[patternLen][wordLen] = res[patternLen - 1][wordLen - 1];
            }
        }
    }

    return res[pattern.size()][word.size()];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string word, pattern;
    cin >> word >> pattern;

    cout << (matches(pattern, word) ? "YES\n" : "NO\n");
}