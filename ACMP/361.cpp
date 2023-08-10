#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int len = s.size();
    for ( ; len; len--) {
        unordered_set<string> substrings;

        for (int i = 0; i + len <= s.size(); i++) {
            string substring = s.substr(i, len);
            sort(substring.begin(), substring.end());
            substrings.insert(substring);
        }

        if (substrings.size() < s.size() - len + 1)
            break;
    }

    cout << len;
}