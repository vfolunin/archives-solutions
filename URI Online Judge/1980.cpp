#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

bool solve() {
    string s;
    cin >> s;

    if (s == "0")
        return 0;

    map<char, int> count;
    for (char c : s)
        count[c]++;

    long long res = factorial(s.size());
    for (auto &[c, k] : count)
        res /= factorial(k);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}