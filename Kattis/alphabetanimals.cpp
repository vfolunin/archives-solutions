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

    string prevWord;
    int wordCount;
    cin >> prevWord >> wordCount;

    vector<vector<string>> wordsBeginWith(26);
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        wordsBeginWith[word[0] - 'a'].push_back(word);
    }

    for (string &word : wordsBeginWith[prevWord.back() - 'a']) {
        if (wordsBeginWith[word.back() - 'a'].empty() ||
            wordsBeginWith[word.back() - 'a'].size() == 1 && word.front() == word.back()) {
            cout << word << "!";
            return 0;
        }
    }

    if (wordsBeginWith[prevWord.back() - 'a'].empty())
        cout << "?";
    else
        cout << wordsBeginWith[prevWord.back() - 'a'].front();
}