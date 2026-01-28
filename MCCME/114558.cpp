#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(const string &s, int i, bool isPrefixOfS, vector<vector<long long>> &memo) {
    long long &res = memo[i][isPrefixOfS];
    if (res != -1)
        return res;

    if (i == s.size())
        return res = 1;

    res = 0;
    int maxDigit = isPrefixOfS ? s[i] - '0' : 8;

    for (int digit = 0; digit <= maxDigit; digit += 2) {
        int nextIsPrefixOfS = isPrefixOfS && digit == maxDigit;

        res += rec(s, i + 1, nextIsPrefixOfS, memo);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r;
    cin >> l >> r;

    string ls = to_string(l - 1), rs = to_string(r);
    ls = string(rs.size() - ls.size(), '0') + ls;

    vector memo(rs.size() + 1, vector<long long>(2, -1));
    long long rCount = rec(rs, 0, 1, memo);

    memo.assign(ls.size() + 1, vector<long long>(2, -1));
    long long lCount = rec(ls, 0, 1, memo);

    cout << rCount - lCount;
}