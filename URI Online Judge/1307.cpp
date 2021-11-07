#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int readBin() {
    string s;
    cin >> s;

    int res = 0;
    for (char c : s)
        res = res * 2 + c - '0';
    return res;
}

void solve(int test) {
    int a = readBin(), b = readBin();

    cout << "Pair #" << test << ": ";
    if (gcd(a, b) > 1)
        cout << "All you need is love!\n";
    else
        cout << "Love is not all you need!\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}