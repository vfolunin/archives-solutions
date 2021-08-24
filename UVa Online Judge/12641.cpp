#include <iostream>
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

string canonize(string s) {
    if (s.size() > 2)
        sort(s.begin() + 1, s.end() - 1);
    return s;
}

void solve() {
    vector<string> dictWords = readWords();

    map<string, string> dict;
    for (string &word : dictWords) {
        string canonized = canonize(word);
        if (!dict.count(canonized))
            dict[canonized] = word;
    }

    vector<string> words = readWords();
    for (int i = 0; i < words.size(); i++) {
        string canonized = canonize(words[i]);
        string res = dict.count(canonized) ? dict[canonized] : words[i];
        cout << res << (i + 1 < words.size() ? " " : "\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}