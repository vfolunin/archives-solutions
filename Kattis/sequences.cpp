#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    map<char, long long> count;
    long long inversionCount = 0, powerOfTwo = 1, prevPowerOfTwo = 0;

    for (char c : s) {
        if (c == '0') {
            inversionCount = (inversionCount + count['1'] * powerOfTwo % MOD) % MOD;
            inversionCount = (inversionCount + count['?'] * prevPowerOfTwo % MOD) % MOD;
        } else if (c == '?') {
            inversionCount = inversionCount * 2 % MOD;
            inversionCount = (inversionCount + count['1'] * powerOfTwo % MOD) % MOD;
            inversionCount = (inversionCount + count['?'] * prevPowerOfTwo % MOD) % MOD;

            prevPowerOfTwo = powerOfTwo;
            powerOfTwo = (powerOfTwo * 2) % MOD;
        }
        count[c]++;
    }

    cout << inversionCount;
}