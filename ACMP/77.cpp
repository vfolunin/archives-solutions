#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long c(int n, int k) {
    if (n < k || k < 0)
        return 0;

    static vector<vector<long long>> memo(30, vector<long long>(30, -1));
    long long &res = memo[n][k];
    if (res != -1)
        return res;

    if (k == 0 || k == n)
        return res = 1;

    return res = c(n - 1, k) + c(n - 1, k - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, zeroCount;
    cin >> n >> zeroCount;

    string s;
    for (; n; n /= 2)
        s += n % 2 + '0';
    reverse(s.begin(), s.end());

    long long res = 0;
    for (int size = zeroCount + 1; size < s.size(); size++)
        res += c(size - 1, zeroCount);

    int seenZeroCount = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0')
            seenZeroCount++;
        else
            res += c(s.size() - i - 1, zeroCount - seenZeroCount - 1);
    }
    res += seenZeroCount == zeroCount;

    cout << res;
}