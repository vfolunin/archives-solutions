#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(const string &s, int i, int lastDigit, bool isPrefixOfS, bool hasLeadingZero,
    vector<vector<vector<vector<long long>>>> &memo) {
    long long &res = memo[i][lastDigit][isPrefixOfS][hasLeadingZero];
    if (res != -1)
        return res;

    if (i == s.size())
        return res = 1;

    res = 0;
    int maxDigit = isPrefixOfS ? s[i] - '0' : 9;

    for (int digit = 0; digit <= maxDigit; digit++) {
        if (i && lastDigit == digit && (lastDigit || digit || !hasLeadingZero))
            continue;

        int nextIsPrefixOfS = isPrefixOfS && digit == maxDigit;
        int nextHasLeadingZero = hasLeadingZero && !digit;

        res += rec(s, i + 1, digit, nextIsPrefixOfS, nextHasLeadingZero, memo);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r;
    cin >> l >> r;

    vector<vector<vector<vector<long long>>>> memo(20, vector<vector<vector<long long>>>(10,
        vector<vector<long long>>(2, vector<long long>(2, -1))));
    long long rCount = rec(to_string(r), 0, 0, 1, 1, memo);

    memo.assign(20, vector<vector<vector<long long>>>(10,
        vector<vector<long long>>(2, vector<long long>(2, -1))));
    long long lCount = rec(to_string(l - 1), 0, 0, 1, 1, memo);

    cout << rCount - lCount;
}