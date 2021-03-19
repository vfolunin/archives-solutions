#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    map<char, string> m;
    string res;

    for (char c : s) {
        if (!m.count(c))
            m[c] = to_string(m.size() + 1);
        res += m[c];
    }

    for (char c : res) {
        static string code = "0153429786";
        cout << code.find(c);
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}