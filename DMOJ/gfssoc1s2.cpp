#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
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

string join(vector<string> &words) {
    string line;
    for (int i = 0; i < words.size(); i++)
        line += words[i] + (i + 1 < words.size() ? " " : "");
    return line;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int replaceCount;
    cin >> replaceCount;

    unordered_map<string, string> replace;
    for (int i = 0; i < replaceCount; i++) {
        string a, b;
        cin >> a >> b;

        replace[b] = a;
    }

    string line;
    cin.ignore();
    getline(cin, line);
    line.pop_back();

    vector<string> words = split(line);
    for (string &word : words)
        if (auto it = replace.find(word); it != replace.end())
            word = it->second;

    cout << join(words) << ".";
}