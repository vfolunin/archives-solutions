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
    getline(cin, s);

    const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int base = 2;

    for (char c : s) {
        if (int digit = DIGITS.find(c); digit != -1) {
            base = max(base, digit + 1);
        } else {
            cout << -1;
            return 0;
        }
    }

    cout << base;
}