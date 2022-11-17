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

    bool hasLower = 0, hasUpper = 0, hasDigit = 0;
    for (char c : s) {
        hasLower |= (bool)islower(c);
        hasUpper |= (bool)isupper(c);
        hasDigit |= (bool)isdigit(c);
    }

    if (s.size() >= 8 && hasLower && hasUpper && hasDigit)
        cout << "YES";
    else
        cout << "NO";
}