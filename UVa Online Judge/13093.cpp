#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    if (!(getline(cin, line)))
        return {};

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

bool solve() {
    vector<string> a = readWords();
    if (a.empty())
        return 0;
    vector<string> b = readWords();
    
    if (a.size() != b.size()) {
        cout << "no\n";
        return 1;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i][0] != b[i][0]) {
            cout << "no\n";
            return 1;
        }
    }

    cout << "yes\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}