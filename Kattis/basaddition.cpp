#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

long long toDec(string s, int base) {
    long long res = 0;
    for (char c : s)
        res = res * base + DIGITS.find(c);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b, c;
    cin >> a >> b >> c;

    int minBase = 2;
    for (string s : { a, b, c })
        for (char c : s)
            minBase = max<int>(minBase, DIGITS.find(c) + 1);

    for (int base = minBase; base <= 16; base++)
        if (toDec(a, base) + toDec(b, base) == toDec(c, base))
            cout << base << "\n";
}