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
        res = min<long long>(1e10, res * base + DIGITS.find(c));
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a;
    long long b;
    cin >> a >> b;

    for (int base = DIGITS.find(*max_element(a.begin(), a.end())) + 1; base < 37; base++) {
        if (toDec(a, base) == b) {
            cout << base;
            return 0;
        }
    }

    cout << 0;
}