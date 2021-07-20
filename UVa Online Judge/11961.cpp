#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int mutationCount, int i, string &s, set<string> &ss) {
    if (!mutationCount) {
        ss.insert(s);
        return;
    }
    if (i == s.size())
        return;

    char prevC = s[i];
    rec(mutationCount, i + 1, s, ss);

    for (char c : string("ACGT")) {
        s[i] = c;
        rec(mutationCount - 1, i + 1, s, ss);
    }

    s[i] = prevC;
}

void solve() {
    int size, mutationCount;
    string s;
    cin >> size >> mutationCount >> s;

    set<string> ss;
    rec(mutationCount, 0, s, ss);

    cout << ss.size() << "\n";
    for (const string &s : ss)
        cout << s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}