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

    int wordCount, queryCount;
    cin >> wordCount >> queryCount;

    vector<string> res(26 * 26 * 26);
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        unordered_map<char, int> l, r;
        for (char c : word)
            r[c]++;

        for (char c : word) {
            if (!--r[c])
                r.erase(c);

            for (auto &[lc, _] : l) {
                for (auto &[rc, _] : r) {
                    int key = ((lc - 'a') * 26 + c - 'a') * 26 + rc - 'a';
                    if (res[key].empty())
                        res[key] = word;
                }
            }

            l[c]++;
        }
    }

    for (int i = 0; i < queryCount; i++) {
        string s;
        cin >> s;

        int key = ((s[0] - 'A') * 26 + s[1] - 'A') * 26 + s[2] - 'A';
        cout << (!res[key].empty() ? res[key] : "No valid word") << "\n";
    }
}