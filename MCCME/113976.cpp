#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long factor;
    string s;
    cin >> factor >> s;
    reverse(s.begin(), s.end());

    const long long MOD = 1e9 + 7;
    long long res = 0;
    for (char c : s)
        res = (res * factor + (c == 'G')) % MOD;

    cout << res;
}