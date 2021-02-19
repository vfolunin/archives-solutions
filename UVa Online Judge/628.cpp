#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(string &rule, int i, vector<string> &words, vector<string> &seq) {
    if (i == rule.size()) {
        for (string &s : seq)
            cout << s;
        cout << "\n";
        return;
    }
    if (rule[i] == '#') {
        for (const string &word : words) {
            seq.push_back(word);
            rec(rule, i + 1, words, seq);
            seq.pop_back();
        } 
    } else {
        for (char c = '0'; c <= '9'; c++) {
            seq.push_back(string(1, c));
            rec(rule, i + 1, words, seq);
            seq.pop_back();
        }
    }
}

bool solve() {
    int wordCount;
    if (!(cin >> wordCount))
        return 0;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    int ruleCount;
    cin >> ruleCount;

    cout << "--\n";
    for (int i = 0; i < ruleCount; i++) {
        string rule;
        cin >> rule;

        vector<string> seq;
        rec(rule, 0, words, seq);
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}