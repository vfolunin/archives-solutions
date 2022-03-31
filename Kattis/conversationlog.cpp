#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line, char delimiter) {
    vector<string> words;
    string word;

    for (char c : line) {
        if (c != delimiter) {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);

    return words;
}

bool compare(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int lineCount;
    cin >> lineCount;

    set<string> authors;
    map<string, set<string>> authorsOf;
    map<string, int> occurenceCount;

    for (int i = 0; i < lineCount; i++) {
        string author;
        cin >> author;
        authors.insert(author);

        string line;
        cin.ignore();
        getline(cin, line);

        for (const string &word : split(line, ' ')) {
            authorsOf[word].insert(author);
            occurenceCount[word]++;
        }
    }

    vector<pair<string, int>> commonWords;
    for (auto &[word, wordAuthors] : authorsOf)
        if (wordAuthors.size() == authors.size())
            commonWords.push_back({ word, occurenceCount[word] });

    sort(commonWords.begin(), commonWords.end(), compare);

    if (commonWords.empty()) {
        cout << "ALL CLEAR";
    } else {
        for (auto &[word, _] : commonWords)
            cout << word << "\n";
    }
}