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

    int base;
    long long mod;
    string s;
    cin >> base >> mod >> mod >> s;

    const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long long res = 0;

    for (char c : s)
        res = (res * base + DIGITS.find(c)) % mod;

    cout << res;
}