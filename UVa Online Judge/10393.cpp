#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int fingerCount, wordCount;
    if (!(cin >> fingerCount >> wordCount))
        return 0;

    vector<int> fingerUsed(10);
    for (int i = 0; i < fingerCount; i++) {
        int x;
        cin >> x;
        fingerUsed[x - 1] = 1;
    }

    static string letters = "qazwsxedcrfvtgbyhnujmikolp";
    static string fingers = "00011122233333366666677889";

    set<string> longestWords;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        bool ok = 1;
        for (char c : word)
            ok &= !fingerUsed[fingers[letters.find(c)] - '0'];

        if (ok) {
            if (!longestWords.empty() && word.size() > longestWords.begin()->size())
                longestWords.clear();
            if (longestWords.empty() || word.size() == longestWords.begin()->size())
                longestWords.insert(word);
        }
    }

    cout << longestWords.size() << "\n";
    for (const string &word : longestWords)
        cout << word << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}