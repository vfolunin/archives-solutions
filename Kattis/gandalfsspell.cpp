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

    string chars;
    cin >> chars;

    vector<string> strings;
    for (string s; cin >> s; )
        strings.push_back(s);

    if (chars.size() != strings.size()) {
        cout << "False";
        return 0;
    }

    unordered_map<char, string> c2s;
    unordered_map<string, char> s2c;

    for (int i = 0; i < chars.size(); i++) {
        if (!c2s.count(chars[i]) && !s2c.count(strings[i])) {
            c2s[chars[i]] = strings[i];
            s2c[strings[i]] = chars[i];
        } else if (c2s[chars[i]] != strings[i] || s2c[strings[i]] != chars[i]) {
            cout << "False";
            return 0;
        }
    }

    cout << "True";
}