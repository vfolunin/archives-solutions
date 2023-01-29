#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int size, string &letters, string &word, vector<string> &words) {
    if (word.size() == size) {
        words.push_back(word);
        return;
    }

    for (char letter : letters) {
        word.push_back(letter);
        rec(size, letters, word, words);
        word.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string letters;
    int size;
    cin >> letters >> size;

    string word;
    vector<string> words;
    rec(size, letters, word, words);

    for (string &word : words)
        cout << word << "\n";
    cout << words.size();
}