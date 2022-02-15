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

void solve() {
    vector<string> words = readWords();

    set<string> known;
    while (1) {
        vector<string> words = readWords();
        if (words.size() == 3)
            known.insert(words.back());
        else
            break;
    }

    for (string &word : words)
        if (!known.count(word))
            cout << word << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}