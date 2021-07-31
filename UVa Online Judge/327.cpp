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

    cout << "Expression: " << s << "\n";
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    vector<int> prefix(26), postfix(26);
    for (char c = 'a'; c <= 'z'; c++) {
        if (int pos = s.find(string("++") + c); pos != -1) {
            prefix[c - 'a'] = 1;
            s.erase(pos, 2);
        } else if (int pos = s.find(string("--") + c); pos != -1) {
            prefix[c - 'a'] = -1;
            s.erase(pos, 2);
        } else if (int pos = s.find(c + string("++")); pos != -1) {
            postfix[c - 'a'] = 1;
            s.erase(pos + 1, 2);
        } else if (int pos = s.find(c + string("--")); pos != -1) {
            postfix[c - 'a'] = -1;
            s.erase(pos + 1, 2);
        }
    }

    int value = 0;
    if (!s.empty())
        value += prefix[s[0] - 'a'] + (s[0] - 'a' + 1);
    for (int i = 2; i < s.size(); i += 2) {
        if (s[i - 1] == '+')
            value += prefix[s[i] - 'a'] + (s[i] - 'a' + 1);
        else
            value -= prefix[s[i] - 'a'] + (s[i] - 'a' + 1);
    }
    cout << "    value = " << value << "\n";

    for (char c = 'a'; c <= 'z'; c++)
        if (s.find(c) != -1)
            cout << "    " << c << " = " << prefix[c - 'a'] + (c - 'a' + 1) + postfix[c - 'a'] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}