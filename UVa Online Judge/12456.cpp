#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int digitCount;
    cin >> digitCount;

    if (!digitCount)
        return 0;

    long long total = 1, palindrome = 1;
    for (int i = 0; i < digitCount; i++) {
        int base;
        cin >> base;
        total *= base;
        if (i * 2 < digitCount)
            palindrome *= base;
    }

    cout << total - palindrome << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}