#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int lcp(const string &a, const string &b) {
    int res = 0;
    while (res < a.size() && res < b.size() && a[res] == b[res])
        res++;
    return res;
}

string firstWord;

bool compare(const string &a, const string &b) {
    int ap = lcp(firstWord, a), bp = lcp(firstWord, b);
    if (ap != bp)
        return ap > bp;
    return a < b;
}

void solve() {
    int wordCount;
    cin >> wordCount;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;
    
    firstWord = words[0];
    sort(words.begin() + 1, words.end(), compare);

    int res = words[0].size();
    for (int i = 1; i < words.size(); i++)
        res += words[i].size() - lcp(words[i - 1], words[i]);

    cout << res << "\n";
    for (string &word : words)
        cout << word << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}