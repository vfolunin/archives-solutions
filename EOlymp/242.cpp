#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

void rec(string &s, int i, int cur, int &res) {
    if (i == s.size()) {
        if (isPrime(cur))
            res = max(res, cur);
        return;
    }
    rec(s, i + 1, cur, res);
    rec(s, i + 1, cur * 10 + s[i] - '0', res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int res = 0;
    rec(s, 0, 0, res);

    cout << res;
}