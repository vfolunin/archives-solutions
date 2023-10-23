#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text, pattern;
    cin >> text >> pattern;

    if (text.find('?') != -1 || text.find('*') != -1)
        swap(text, pattern);

    vector<vector<int>> matches(text.size() + 1, vector<int>(pattern.size() + 1));

    matches[0][0] = 1;
    for (int patternLen = 1; patternLen <= pattern.size(); patternLen++)
        matches[0][patternLen] = matches[0][patternLen - 1] && pattern[patternLen - 1] == '*';

    for (int textLen = 1; textLen <= text.size(); textLen++) {
        for (int patternLen = 1; patternLen <= pattern.size(); patternLen++) {
            if (isalpha(pattern[patternLen - 1])) {
                matches[textLen][patternLen] = matches[textLen - 1][patternLen - 1] && text[textLen - 1] == pattern[patternLen - 1];
            } else if (pattern[patternLen - 1] == '?') {
                matches[textLen][patternLen] = matches[textLen - 1][patternLen - 1];
            } else {
                for (int prevTextLen = 0; prevTextLen <= textLen; prevTextLen++)
                    matches[textLen][patternLen] |= matches[prevTextLen][patternLen - 1];
            }
        }
    }

    cout << (matches[text.size()][pattern.size()] ? "YES" : "NO");
}