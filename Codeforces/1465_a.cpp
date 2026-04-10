#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s >> s;

    int bracketCount = 0;
    while (bracketCount < s.size() && s[s.size() - 1 - bracketCount] == ')')
        bracketCount++;

    cout << (bracketCount * 2 > s.size() ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}