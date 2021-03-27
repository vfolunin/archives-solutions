#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

multiset<int> getCounts(string &s) {
    map<char, int> count;
    for (char c : s)
        count[c]++;
    multiset<int> counts;
    for (auto &[_, k] : count)
        counts.insert(k);
    return counts;
}

bool solve() {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    cout << (getCounts(a) == getCounts(b) ? "YES\n" : "NO\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}