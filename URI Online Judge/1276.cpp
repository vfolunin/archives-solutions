#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!getline(cin, s))
        return 0;

    vector<int> has(26);
    for (char c : s)
        if (islower(c))
            has[c - 'a'] = 1;

    vector<pair<int, int>> ranges;
    for (int i = 0; i < 26; i++) {
        if (has[i]) {
            if (ranges.empty() || ranges.back().second + 1 < i)
                ranges.push_back({ i, i });
            else
                ranges.back().second++;
        }
    }

    for (int i = 0; i < ranges.size(); i++) {
        cout << (char)('a' + ranges[i].first) << ":" << (char)('a' + ranges[i].second);
        if (i + 1 < ranges.size())
            cout << ", ";
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}