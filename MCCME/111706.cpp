#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool contains(string text, string &suffix, string &word) {
    while (text.size() < word.size() * 2)
        text += text;
    text += suffix;
    return text.find(word) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text, word;
    cin >> text >> word;

    for (int suffixSize = 0; 1; suffixSize++) {
        string suffix = word.substr(word.size() - suffixSize);
        if (contains(text, suffix, word)) {
            cout << suffix;
            return 0;
        }
    }
}