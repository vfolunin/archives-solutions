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

int upperCount(string &s) {
    int res = 0;
    for (char c : s)
        res += (bool)isupper(c);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    unordered_map<string, unordered_set<string>> words;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        words[toLower(word)].insert(word);
    }

    int res = 0;

    string word;
    while (cin >> word) {
        string lowerWord = toLower(word);
        if (words.count(lowerWord))
            res += !words[lowerWord].count(word);
        else
            res += upperCount(word) != 1;
    }

    cout << res;
}