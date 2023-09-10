#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line, const string &separators) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (separators.find(c) == -1) {
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

string join(vector<string> &words, const string &separator) {
    string line;
    for (int i = 0; i < words.size(); i++)
        line += words[i] + (i + 1 < words.size() ? separator : "");
    return line;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    getline(cin, line);

    vector<string> sentences = split(line, ".");

    for (string &sentence : sentences) {
        vector<string> words = split(sentence, " ");
        reverse(words.begin(), words.end());
        sentence = join(words, " ");
    }

    cout << join(sentences, ". ") << ".";
}