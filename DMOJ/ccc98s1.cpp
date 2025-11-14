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

string join(vector<string> &words) {
    string line;
    for (int i = 0; i < words.size(); i++)
        line += words[i] + (i + 1 < words.size() ? " " : "");
    return line;
}

void solve() {
    string line;
    getline(cin, line);

    vector<string> words = split(line);
    for (string &word : words)
        if (word.size() == 4)
            word = "****";

    cout << join(words) << "\n";
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