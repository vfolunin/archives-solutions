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

    string sortedS = s;
    sort(sortedS.begin(), sortedS.end());

    int diff = 0;
    for (int i = 0; i < s.size(); i++)
        diff += s[i] != sortedS[i];

    cout << diff / 2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}