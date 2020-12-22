#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool hasSubsequence(string &t, string &s) {
    int si = 0;
    for (int ti = 0; ti < t.size() && si < s.size(); ti++)
        if (t[ti] == s[si])
            si++;
    return si == s.size();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s, t;
    while (cin >> s >> t)
        cout << (hasSubsequence(t, s) ? "Yes\n" : "No\n");
}