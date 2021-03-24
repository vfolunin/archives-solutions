#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int wordLen, wordCount;
    cin >> wordLen >> wordCount;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    int res = wordLen;
    for (int i = 1; i < wordCount; i++) {
        int commonLen = wordLen;
        while (words[i - 1].substr(wordLen - commonLen, commonLen) != words[i].substr(0, commonLen)) {
            commonLen--;
            res++;
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}