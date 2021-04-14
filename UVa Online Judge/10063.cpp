#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(string &s, string p) {
    if (p.size() == s.size()) {
        cout << p << "\n";
        return;
    }

    for (int i = 0; i <= p.size(); i++) {
        string np = p;
        np.insert(i, 1, s[p.size()]);
        rec(s, np);
    }
}

bool solve(int test) {
    string s;
    if (!(cin >> s))
        return 0;

    if (test)
        cout << "\n";
    rec(s, "");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}