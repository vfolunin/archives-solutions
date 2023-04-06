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

    string digits = "0123456789ABCDEF";
    int value = 0;

    for (int i = 0; i < s.size(); i++) {
        value = value * 2 + s[i] - '0';
        if ((s.size() - 1 - i) % 4 == 0) {
            cout << digits[value];
            value = 0;
        }
    }
}