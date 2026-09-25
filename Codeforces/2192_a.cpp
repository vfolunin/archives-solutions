#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getBlockCount(string &s) {
    int blockCount = 1;
    for (int i = 1; i < s.size(); i++)
        blockCount += s[i - 1] != s[i];
    return blockCount;
}

void solve() {
    string s;
    cin >> s >> s;

    int maxBlockCount = getBlockCount(s);
    for (int i = 1; i < s.size(); i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        maxBlockCount = max(maxBlockCount, getBlockCount(s));
    }

    cout << maxBlockCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}