#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

vector<string> split(string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (c != ' ') {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);
    return words;
}

string join(vector<string> &words) {
    string line;
    for (int i = 0; i < words.size(); i++)
        line += words[i] + (i + 1 < words.size() ? " " : "");
    return line;
}

void solve() {
    string s;
    getline(cin, s);

    unordered_map<string, string> replaces = {
        { "8", "ate" },
        { "w8", "wait" },
        { "gr8", "great" },
        { "4", "for" },
        { "b4", "before" }
    };

    vector<string> words = split(s);
    for (string &word : words)
        if (auto it = replaces.find(word); it != replaces.end())
            word = it->second;

    cout << join(words) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.get();

    for (int i = 0; i < n; i++)
        solve();
}