#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(string &letters, int size, string &word, vector<string> &words) {
    if (word.size() == size) {
        for (int i = 0; i + 1 < size; i++) {
            if (word[i] == word[i + 1]) {
                words.push_back(word);
                break;
            }
        }
        return;
    }
    for (char letter : letters) {
        word.push_back(letter);
        rec(letters, size, word, words);
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
    rec(letters, size, word, words);

    for (string &word : words)
        cout << word << "\n";
    cout << words.size();
}