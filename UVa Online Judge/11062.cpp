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
    char c;
    cin >> noskipws;
    while (cin >> c) {
        if (c == '-') {
            if (cin.peek() == '\n')
                cin >> c;
            else
                word += c;
        } else if (isalpha(c)) {
            word += tolower(c); 
        } else if (!word.empty()) {
            words.insert(word);
            word = "";
        }
    }
    if (!word.empty())
        words.insert(word);

    for (const string &word : words)
        cout << word << "\n";
}