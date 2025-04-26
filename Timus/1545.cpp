#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<char, set<string>> words;
    for (int i = 0; i < size; i++) {
        string word;
        cin >> word;

        words[word[0]].insert(word);
    }

    char c;
    cin >> c;

    for (const string &word : words[c])
        cout << word << "\n";
}