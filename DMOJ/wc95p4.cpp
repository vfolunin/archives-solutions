#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool matches(const string &word, const string &pattern) {
    vector<vector<int>> match(word.size() + 1, vector<int>(pattern.size() + 1));

    match[0][0] = 1;
    for (int patternLen = 1; patternLen <= pattern.size(); patternLen++)
        match[0][patternLen] = match[0][patternLen - 1] && pattern[patternLen - 1] == '*';

    for (int wordLen = 1; wordLen <= word.size(); wordLen++) {
        for (int patternLen = 1; patternLen <= pattern.size(); patternLen++) {
            if (pattern[patternLen - 1] == '*') {
                for (int prevWordLen = 0; prevWordLen <= wordLen; prevWordLen++)
                    match[wordLen][patternLen] |= match[prevWordLen][patternLen - 1];
            } else if (pattern[patternLen - 1] == '?') {
                match[wordLen][patternLen] = match[wordLen - 1][patternLen - 1];
            } else {
                match[wordLen][patternLen] = match[wordLen - 1][patternLen - 1] && word[wordLen - 1] == pattern[patternLen - 1];
            }
        }
    }

    return match[word.size()][pattern.size()];
}

bool solve() {
    int wordCount;
    if (!(cin >> wordCount))
        return 0;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    for (int i = 0; i < 5; i++) {
        string pattern;
        cin >> pattern;

        vector<string> matchWords;
        for (string &word : words)
            if (matches(word, pattern))
                matchWords.push_back(word);

        if (matchWords.empty()) {
            cout << "NO MATCH\n";
        } else {
            for (int i = 0; i < matchWords.size(); i++)
                cout << matchWords[i] << (i + 1 < matchWords.size() ? ", " : "\n");
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    while (solve());
}