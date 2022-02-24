#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    getline(cin, line);

    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word)
        words.push_back(word);

    return words;
}

string pigLatin(string &s) {
    static const string VOWELS = "aeiouy";
    if (VOWELS.find(tolower(s[0])) != -1)
        return s + "yay";

    int i = 0;
    while (i < s.size() && VOWELS.find(tolower(s[i])) == -1)
        i++;
    return s.substr(i) + s.substr(0, i) + "ay";
}

bool solve() {
    vector<string> words = readWords();
    if (words.empty())
        return 0;

    for (string &word : words)
        cout << pigLatin(word) << " ";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}