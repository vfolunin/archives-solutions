#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string rec(string s) {
    if (s.empty() || s.find('0') != -1)
        return "";
    if (s[0] == '2')
        return s.substr(1);
    if (s[0] == '3') {
        string r = rec(s.substr(1));
        if (r.empty())
            return "";
        return r + "2" + r;
    }
    return "";
}

bool solve() {
    string s;
    cin >> s;

    if (s == "0")
        return 0;

    string r = rec(s);

    cout << (r.empty() ? "NOT ACCEPTABLE" : r) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}