#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const string &a, const string &b) {
    return a.substr(0, 2) < b.substr(0, 2);
}

bool solve() {
    int wordCount;
    cin >> wordCount;

    if (!wordCount)
        return 0;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    stable_sort(words.begin(), words.end(), compare);

    for (string &word : words)
        cout << word << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}