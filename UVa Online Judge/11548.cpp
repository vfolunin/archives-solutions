#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int match(string &a, string &b, int shift) {
    int res = 0;
    for (int ai = shift, bi = 0; ai < (int)a.size() && bi < (int)b.size(); ai++, bi++)
        res += 0 <= ai && a[ai] == b[bi];
    return res;
}

void solve() {
    int wordCount;
    cin >> wordCount;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    int res = 0;
    for (int i = 0; i < wordCount; i++)
        for (int j = i + 1; j < wordCount; j++)
            for (int shift = -words[j].size() + 1; shift < (int)words[i].size(); shift++)
                res = max(res, match(words[i], words[j], shift));
    
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