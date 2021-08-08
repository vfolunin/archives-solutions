#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    set<string> substrings;
    for (int len = 1; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            string substring = s.substr(l, len), minSubstring = substring;
            for (int i = 0; i < len - 1; i++) {
                rotate(substring.begin(), substring.begin() + 1, substring.end());
                minSubstring = min(minSubstring, substring);
            }
            substrings.insert(minSubstring);
        }
    }

    cout << substrings.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}