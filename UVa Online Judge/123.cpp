#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (c != ' ') {
            word += tolower(c);
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
    return words;
}

string join(vector<string> &words) {
    string line;
    for (int i = 0; i < words.size(); i++)
        line += words[i] + (i + 1 < words.size() ? " " : "");
    return line;
}

string toUpper(string s) {
    for (char &c : s)
        c = toupper(c);
    return s;
}

bool compare(const pair<string, string> &a, const pair<string, string> &b) {
    return a.first < b.first;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    set<string> ignoredWords;
    while (1) {
        string word;
        cin >> word;
        if (word == "::")
            break;
        ignoredWords.insert(word);
    }
    cin.ignore();

    vector<pair<string, string>> answer;

    string line;
    while (getline(cin, line)) {
        vector<string> words = split(line);
        for (string &word : words) {
            if (!word.empty() && !ignoredWords.count(word)) {
                string w = word;
                word = toUpper(word);
                answer.push_back({ word, join(words) });
                word = w;
            }
        }
    }

    stable_sort(answer.begin(), answer.end(), compare);
    for (auto &[_, line] : answer)
        cout << line << "\n";
}