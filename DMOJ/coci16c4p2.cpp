#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    string query;
    cin >> query;

    unordered_set<char> letters;
    for (string &word : words)
        if (word.size() > query.size() && word.substr(0, query.size()) == query)
            letters.insert(word[query.size()]);

    cout << "***";
    for (char c = 'A'; c <= 'Z'; c++) {
        cout << (letters.count(c) ? c : '*');
        if ((c - 'A') % 8 == 4)
            cout << "\n";
    }
    cout << "***";
}