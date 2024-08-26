#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isDivisible(string &s, int divisor) {
    int remainder = 0;
    for (char c : s)
        remainder = (remainder * 2 + c - '0') % divisor;
    return !remainder;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    if (isDivisible(s, 15))
        cout << "BOTH";
    else if (isDivisible(s, 3))
        cout << "FIRST";
    else if (isDivisible(s, 5))
        cout << "SECOND";
    else
        cout << "NONE";
}