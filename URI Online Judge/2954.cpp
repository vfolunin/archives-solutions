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
        if (isalpha(c)) {
            word += tolower(c);
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);

    return words;
}

void solve() {
    string line;
    getline(cin, line);

    vector<string> words = split(line);

    int res = 0, cur = 0;
    for (string &word : words) {
        cur += word.size();
        res = max(res, cur);
        if (word == "jogo" || word == "perdi")
            cur = 0;
    }

    cout << res << "\n";
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