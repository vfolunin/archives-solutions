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
        if (c != '-') {
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

bool solve() {
    string line;
    if (!(cin >> line))
        return 0;

    vector<string> words = split(line);
    string cobol = "cobol";
    bool ok = 1;

    for (int i = 0; i < 5; i++)
        ok &= tolower(words[i].front()) == cobol[i] ||
              tolower(words[i].back()) == cobol[i];

    cout << (ok ? "GRACE HOPPER\n" : "BUG\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}