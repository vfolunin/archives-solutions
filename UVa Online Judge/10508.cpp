#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int diff(string &a, string &b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] != b[i];
    return res;
}

bool solve() {
    int wordCount, wordLen;
    if (!(cin >> wordCount >> wordLen))
        return 0;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    for (int i = 1; i < wordCount; i++) {
        for (int j = i; 1; j++) {
            if (diff(words[i - 1], words[j]) == 1) {
                swap(words[i], words[j]);
                break;
            }
        }
    }

    for (string &word : words)
        cout << word << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}