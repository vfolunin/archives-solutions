#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

string toLower(string s) {
    for (char &c : s)
        c = tolower(c);
    return s;
}

bool isId(string &word, string &canStartWithDigit, unordered_set<string> &keywords) {
    bool hasLetter = 0;
    for (char c : word)
        hasLetter |= isalpha(c) || c == '_';
    if (!hasLetter)
        return 0;

    if (isdigit(word[0]) && canStartWithDigit == "no")
        return 0;

    return !keywords.count(word);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int keywordCount;
    string caseSensitive, canStartWithDigit;
    cin >> keywordCount >> caseSensitive >> canStartWithDigit;

    unordered_set<string> keywords;
    for (int i = 0; i < keywordCount; i++) {
        string keyword;
        cin >> keyword;
        if (caseSensitive == "no")
            keyword = toLower(keyword);
        keywords.insert(keyword);
    }

    string word, res;
    unordered_map<string, int> count, index;
    char c;
    while (cin >> noskipws >> c) {
        if (isalnum(c) || c == '_') {
            word += c;
        } else {
            if (caseSensitive == "no")
                word = toLower(word);
            if (isId(word, canStartWithDigit, keywords)) {
                count[word]++;
                if (!index.count(word))
                    index[word] = index.size();
                if (res.empty() || count[res] < count[word] || count[res] == count[word] && index[res] > index[word])
                    res = word;
            }
            word.clear();
        }
    }

    if (caseSensitive == "no")
        word = toLower(word);
    if (isId(word, canStartWithDigit, keywords)) {
        count[word]++;
        if (!index.count(word))
            index[word] = index.size();
        if (res.empty() || count[res] < count[word] || count[res] == count[word] && index[res] > index[word])
            res = word;
    }

    cout << res;
}