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

    string s;
    cin >> s;

    unordered_map<char, vector<int>> pos;
    for (int i = 0; i < s.size(); i++)
        pos[s[i]].push_back(i);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        string s = "ATGC";
        
        vector<pair<int, int>> pairs(s.size());
        for (int j = 0; j < s.size(); j++)
            pairs[j] = { j, upper_bound(pos[s[j]].begin(), pos[s[j]].end(), r) - lower_bound(pos[s[j]].begin(), pos[s[j]].end(), l) };

        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        });

        for (auto &[j, _] : pairs)
            cout << s[j];
        cout << "\n";
    }
}