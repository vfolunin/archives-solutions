#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

set<string> readDict() {
    int dictSize;
    cin >> dictSize;

    set<string> dict;
    for (int i = 0; i < dictSize; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        dict.insert(s);
    }
    return dict;
}

void solve(set<string> &dict) {
    int letterCount;
    cin >> letterCount;

    vector<pair<char, int>> letters(letterCount);
    for (auto &[letter, score] : letters)
        cin >> letter >> score;
    sort(letters.begin(), letters.end());

    int res = 0;

    for (int mask = 0; mask < (1 << letterCount); mask++) {
        string s;
        int score = 0;
        for (int bit = 0; bit < letterCount; bit++) {
            if (mask & (1 << bit)) {
                s += letters[bit].first;
                score += letters[bit].second;
            }
        }
        if (dict.count(s))
            res = max(res, score);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    set<string> dict = readDict();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(dict);
}