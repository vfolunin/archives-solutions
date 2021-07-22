#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void addSubstitute(const string &substitute, map<string, int> &dict, set<int> &substitutes) {
    if (dict.count(substitute))
        substitutes.insert(dict[substitute]);
}

set<int> getSubstitutes(string &word, map<string, int> &dict) {
    set<int> substitutes;

    for (int i = 0; i < word.size(); i++) {
        addSubstitute(word.substr(0, i) + word.substr(i + 1), dict, substitutes);
        for (char c = 'a'; c <= 'z'; c++) {
            addSubstitute(word.substr(0, i) + c + word.substr(i + 1), dict, substitutes);
            addSubstitute(word.substr(0, i) + c + word.substr(i), dict, substitutes);
        }
    }

    for (char c = 'a'; c <= 'z'; c++)
        addSubstitute(word + c, dict, substitutes);

    return substitutes;
}

void solve(int test) {
    vector<string> words;
    map<string, int> dict;

    for (int i = 0; 1; i++) {
        string word;
        cin >> word;

        if (word == "#")
            break;

        words.push_back(word);
        dict[word] = i;
    }

    if (test)
        cout << "\n";

    while (1) {
        string word;
        cin >> word;

        if (word == "#")
            break;

        if (dict.count(word)) {
            cout << word << " is correct\n";
        } else {
            cout << word << ":";
            for (int i : getSubstitutes(word, dict))
                cout << " " << words[i];
            cout << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}