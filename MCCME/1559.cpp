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

    int digitCount = 0, letterCount = 0;
    for (char c; c != '.'; cin >> c) {
        digitCount += (bool)isdigit(c);
        letterCount += (bool)isalpha(c);
    }

    cout << digitCount << " " << letterCount;
}