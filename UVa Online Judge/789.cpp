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

    char c;
    cin >> c;
    cin.ignore();

    map<string, set<int>> res;

    for (int lineNumber = 1; 1; lineNumber++) {
        string line;
        if (!getline(cin, line))
            break;

        vector<string> words = split(line);
        for (string &word : words)
            if (word[0] == c)
                res[word].insert(lineNumber);
    }

    for (auto &[word, lines] : res) {
        cout << word;
        for (int line : lines)
            cout << " " << line;
        cout << "\n";
    }
}