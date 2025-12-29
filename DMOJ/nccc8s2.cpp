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

    string s;
    cin >> s;

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;

    long long res = 1;
    const long long MOD = 1e9 + 7;
    for (int count : count)
        res = res * (count + 1) % MOD;

    cout << res << "\n";
}