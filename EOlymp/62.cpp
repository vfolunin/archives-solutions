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

    const long long MOD = 1e9 + 7;

    long long remainder = 0;
    for (char c : s)
        remainder = (remainder * 10 + c - '0') % MOD;

    long long res = 1, resRemainder = 1;
    while (remainder != resRemainder) {
        res++;
        resRemainder = resRemainder * res % MOD;
    }

    cout << res;
}