#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<int> &digits, int digitIndex, int numberMod, int digitMod, int mod, bool less,
        vector<vector<vector<vector<int>>>> &memo) {
    int &res = memo[digitIndex][numberMod][digitMod][less];
    if (res != -1)
        return res;

    if (digitIndex == digits.size())
        return res = !numberMod && !digitMod;

    res = 0;
    for (int digit = 0; digit < 10; digit++) {
        int nextNumberMod = (numberMod * 10 + digit) % mod;
        int nextDigitMod = (digitMod + digit) % mod;
        if (less)
            res += rec(digits, digitIndex + 1, nextNumberMod, nextDigitMod, mod, 1, memo);
        else if (digit <= digits[digitIndex])
            res += rec(digits, digitIndex + 1, nextNumberMod, nextDigitMod, mod, digit < digits[digitIndex], memo);
    }
    return res;
}

int calc(int n, int mod) {
    vector<int> digits;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());

    vector<vector<vector<vector<int>>>> memo(digits.size() + 1,
        vector<vector<vector<int>>>(100,
            vector<vector<int>>(100, vector<int>(2, -1))
        )
    );

    return rec(digits, 0, 0, 0, mod, 0, memo);
}

int calc(int l, int r, int mod) {
    return calc(r, mod) - calc(l - 1, mod);
}

void solve() {
    int l, r, mod;
    cin >> l >> r >> mod;

    if (mod >= 100)
        cout << "0\n";
    else
        cout << calc(l, r, mod) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}