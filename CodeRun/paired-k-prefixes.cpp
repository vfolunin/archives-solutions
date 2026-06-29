#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

bool can(vector<string> &words, int prefixSize) {
    unordered_map<string, int> count;
    for (string &word : words) {
        if (word.size() < prefixSize)
            return 0;
        count[word.substr(0, prefixSize)]++;
    }

    for (auto &[word, count] : count)
        if (count % 2)
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    int l = 0, r = words[0].size() + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(words, m))
            l = m;
        else
            r = m;
    }

    cout << l;
}