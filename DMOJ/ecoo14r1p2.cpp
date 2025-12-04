#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(string &s) {
    for (char c : s)
        if (c != ' ' && (c < 'A' || c > 'Z'))
            return 0;
    return 1;
}

string decode(string &code) {
    for (int offset = 0; offset < 8; offset++) {
        string res;
        for (int i = offset; i + 7 < code.size(); i += 8) {
            char byte = 0;
            for (int j = 0; j < 8; j++)
                byte = byte * 2 + code[i + j] - '0';
            res += byte;
        }
        if (check(res))
            return res;
    }
    return "";
}

bool solve() {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    string code(a.size(), '0');
    for (int i = 0; i < a.size(); i++)
        code[i] += a[i] == 'A' || a[i] == 'T';
    string res = decode(code);

    if (res.empty()) {
        for (char &c : code)
            c ^= 1;
        res = decode(code);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}