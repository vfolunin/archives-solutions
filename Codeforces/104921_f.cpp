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

    string digits = "1234567890";
    s = "1" + s;

    int res = 4;
    for (int i = 1; i < s.size(); i++)
        res += abs((int)digits.find(s[i - 1]) - (int)digits.find(s[i]));

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