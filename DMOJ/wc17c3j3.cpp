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

    int lowerCount = 0, upperCount = 0, digitCount = 0;
    for (char c : s) {
        lowerCount += (bool)islower(c);
        upperCount += (bool)isupper(c);
        digitCount += (bool)isdigit(c);
    }

    if (8 <= s.size() && s.size() <= 12 && s.size() == lowerCount + upperCount + digitCount &&
        lowerCount >= 3 && upperCount >= 2 && digitCount >= 1)
        cout << "Valid";
    else
        cout << "Invalid";
}