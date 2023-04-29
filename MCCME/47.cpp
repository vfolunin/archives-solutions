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

    while (s.size() % 4)
        s = '0' + s;

    string digits = "0123456789ABCDEF";
    for (int i = 0; i < s.size(); i += 4) {
        int value = 0;
        for (int j = 0; j < 4; j++)
            value = value * 2 + s[i + j] - '0';
        cout << digits[value];
    }
}