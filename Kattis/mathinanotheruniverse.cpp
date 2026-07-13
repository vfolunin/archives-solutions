#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double eval(string &s, int l, int r) {
    int p1 = -1, p2 = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '+' || s[i] == '-' && s[i + 1] == ' ')
            p1 = i;
        if (s[i] == '*' || s[i] == '/')
            p2 = i;
    }
    if (p2 != -1) {
        if (s[p2] == '*')
            return eval(s, l, p2 - 1) * eval(s, p2 + 1, r);
        else
            return eval(s, l, p2 - 1) / eval(s, p2 + 1, r);
    }
    if (p1 != -1) {
        if (s[p1] == '+')
            return eval(s, l, p1 - 1) + eval(s, p1 + 1, r);
        else
            return eval(s, l, p1 - 1) - eval(s, p1 + 1, r);
    }
    return stod(s.substr(l, r - l + 1));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    cout << (int)eval(s, 0, s.size() - 1);
}