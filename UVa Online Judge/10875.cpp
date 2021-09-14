#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const vector<string> BIG = {
    "000 .0. 000 000 0.0 000 0.. 000 000 000 .0. ... 0.0 .0.",
    "0.0 .0. ..0 ..0 0.0 0.. 0.. ..0 0.0 0.0 .0. ... 0.0 ...",
    "0.0 .0. 000 000 000 000 000 ..0 000 000 000 000 .0. 000",
    "0.0 .0. 0.. ..0 ..0 ..0 0.0 ..0 0.0 ..0 .0. ... 0.0 ...",
    "000 .0. 000 000 ..0 000 000 ..0 000 ..0 .0. ... 0.0 .0."
};

const string SMALL = "0123456789+-*/";

char getChar(vector<string> &s, int from) {
    for (int i = 0; i < SMALL.size(); i++) {
        bool ok = 1;

        for (int row = 0; ok && row < 5; row++)
            for (int col = 0; ok && col < 3; col++)
                ok &= BIG[row][4 * i + col] == s[row][from + col];
        
        if (ok)
            return SMALL[i];
    }

    return '?';
}

string getString(vector<string> &s) {
    string res;
    for (int i = 0; i < s[0].size(); i += 4)
        res += getChar(s, i);
    return res;
}

int eval(string &s, int l, int r) {
    int p1 = -1, p2 = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '+' || s[i] == '-')
            p1 = i;
        if (s[i] == '*' || s[i] == '/')
            p2 = i;
    }

    if (p1 != -1) {
        if (s[p1] == '+')
            return eval(s, l, p1 - 1) + eval(s, p1 + 1, r);
        else
            return eval(s, l, p1 - 1) - eval(s, p1 + 1, r);
    }

    if (p2 != -1) {
        if (s[p2] == '*')
            return eval(s, l, p2 - 1) * eval(s, p2 + 1, r);
        else
            return eval(s, l, p2 - 1) / eval(s, p2 + 1, r);
    }

    int res = 0;
    for (int i = l; i <= r; i++)
        res = res * 10 + s[i] - '0';
    return res;
}

void print(const string &s) {
    for (int row = 0; row < 5; row++)
        for (int i = 0; i < s.size(); i++)
            cout << BIG[row].substr(4 * SMALL.find(s[i]), 3) << (i + 1 < s.size() ? " " : "\n");
}

bool solve() {
    vector<string> s(5);
    for (string &row : s)
        getline(cin, row);
    cin.ignore();

    string n = getString(s);
    if (n == "0")
        return 0;

    print(to_string(eval(n, 0, n.size() - 1)));
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}