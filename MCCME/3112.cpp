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

void print(vector<string> &words, const string &before, const string &between, const string &after) {
    cout << before;
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << (i + 1 < words.size() ? between : "");
    cout << after << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    getline(cin, line);
    vector<string> words = split(line);

    print(words, "x=", "*", ".");
    print(words, "", " ", "");
    print(words, "", "", "");
    print(words, "\"", "\",\"", "\"");
}