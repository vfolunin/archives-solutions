#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    getline(cin, line);

    vector<string> words;
    string word;

    for (char c : line) {
        if (c != ' ') {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);

    return words;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<string>> text;
    while (1) {
        vector<string> words = readWords();
        if (words.empty())
            break;
        text.push_back(words);
    }

    vector<int> width;
    for (vector<string> &words : text) {
        width.resize(max(width.size(), words.size()));
        for (int i = 0; i < words.size(); i++)
            width[i] = max<int>(width[i], words[i].size());
    }

    for (vector<string> &words : text) {
        for (int i = 0; i + 1 < words.size(); i++)
            cout << setw(width[i]) << left << words[i] << " ";
        cout << words.back() << "\n";
    }
}