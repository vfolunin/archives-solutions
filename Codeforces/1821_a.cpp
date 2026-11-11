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

    int product = 1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '?')
            product *= (i ? 10 : 9);

    cout << (s[0] != '0' ? product : 0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}