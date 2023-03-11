#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(string &letters, int size, string &word, vector<string> &words) {
    if (word.size() == size) {
        static const string VOWELS = "AEIOU";
        for (int i = 0; i + 1 < size; i++)
            if (VOWELS.find(word[i]) != -1 && VOWELS.find(word[i + 1]) != -1)
                return;
        words.push_back(word);
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