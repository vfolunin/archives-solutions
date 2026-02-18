#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(string &s, int i, string &cur) {
    if (i == s.size()) {
        cout << cur << "\n";
        return;
    }

    cur.push_back(tolower(s[i]));
    rec(s, i + 1, cur);
    cur.pop_back();

    if (s[i] == 'S' && i + 1 < s.size() && s[i + 1] == 'S') {
        cur.push_back('B');
        rec(s, i + 2, cur);
        cur.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    string cur;
    rec(s, 0, cur);
}