#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isSquare(long long n) {
    long long r = sqrt(n);
    return r * r == n;
}

long long toDec(string &s, int base) {
    long long res = 0;
    for (char c : s)
        res = res * base + c - '0';
    return res;
}

bool solve() {
    string s;
    cin >> s;

    if (s == "0")
        return 0;

    int base = *max_element(s.begin(), s.end()) - '0' + 1;
    while (!isSquare(toDec(s, base)))
        base++;

    cout << base << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}