#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int wordCount, wordIndex;
    cin >> wordCount >> wordIndex;

    if (!wordCount && !wordIndex)
        return 0;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    int size = 1;
    while (wordIndex > size) {
        wordIndex -= size;
        size++;
    }

    cout << words[wordIndex - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}