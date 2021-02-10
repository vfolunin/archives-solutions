#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string decode(string &s) {
    string res;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size();) {
        if (s[i] == '1') {
            res += (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
            i += 3;
        } else {
            res += (s[i] - '0') * 10 + (s[i + 1] - '0');
            i += 2;
        }
    }
    return res;
}

string encode(string &s) {
    string res;
    for (int i = s.size() - 1; i >= 0; i--) {
        string code = to_string((int)s[i]);
        reverse(code.begin(), code.end());
        res += code;
    }
    return res;
}

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    if (isdigit(line[0]))
        cout << decode(line) << "\n";
    else
        cout << encode(line) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}