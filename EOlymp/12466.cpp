#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    map<char, int> count;
    for (char c : s)
        count[c]++;

    int res = abs(count['U'] - count['D']) + abs(count['L'] - count['R']);
    res += count['U'] && count['D'] || count['L'] && count['R'];

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}