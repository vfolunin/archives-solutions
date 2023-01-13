#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line, const string &separators) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (separators.find(c) == -1) {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
    return words;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string path;
    cin >> path;

    for (string &part : split(path, "\\"))
        cout << part << "\n";
}