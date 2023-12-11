#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    set<string> words;
    string word;

    for (char c; cin >> noskipws >> c; ) {
        if (isalpha(c)) {
            word += tolower(c);
        } else if (!word.empty()) {
            words.insert(word);
            word.clear();
        }
    }

    for (const string &word : words)
        cout << word << "\n";
}