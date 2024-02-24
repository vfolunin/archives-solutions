#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int inversionCount(string &s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        for (int j = i + 1; j < s.size(); j++)
            res += s[i] > s[j];
    return res;
}

void solve() {
    int size;
    cin >> size >> size;

    vector<pair<string, int>> pairs(size);
    for (auto &[s, inversions] : pairs) {
        cin >> s;
        inversions = inversionCount(s);
    }

    stable_sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    for (auto &[s, inversions] : pairs)
        cout << s << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}