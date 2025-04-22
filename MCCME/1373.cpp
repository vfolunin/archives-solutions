#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool endsWith(string &text, const string &word) {
    for (int i = 0; i < word.size(); i++)
        if (text[text.size() - 1 - i % text.size()] != word[word.size() - 1 - i])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text, word;
    cin >> text >> word;

    for (int suffixSize = 0; 1; suffixSize++) {
        if (endsWith(text, word.substr(0, word.size() - suffixSize))) {
            cout << word.substr(word.size() - suffixSize);
            return 0;
        }
    }
}