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

bool compare(const string &a, const string &b) {
    return a.size() > b.size();
}

void solve() {
    vector<string> words = readWords();
    stable_sort(words.begin(), words.end(), compare);

    for (int i = 0; i < words.size(); i++)
        cout << words[i] << (i + 1 < words.size() ? " " : "\n");
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