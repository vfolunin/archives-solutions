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

    string digits = "0123456789ABCDEF", res;
    for (char c : s) {
        int digit = digits.find(c);
        for (int bit = 3; bit >= 0; bit--)
            res += ((digit >> bit) & 1) + '0';
    }

    cout << res;
}