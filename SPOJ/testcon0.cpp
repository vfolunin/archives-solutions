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

    string digits = "0123456789ABCDEF";

    for (int i = 0, value = 0; i < 32; i++) {
        char c;
        cin >> c;

        value = value * 2 + c - '0';

        if (i % 4 == 3) {
            cout << digits[value];
            value = 0;
        }
    }
}