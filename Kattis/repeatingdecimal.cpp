#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int num, den, digitCount;
    if (!(cin >> num >> den >> digitCount))
        return 0;

    cout << "0.";
    for (int i = 0; i < digitCount; i++) {
        cout << num * 10 / den;
        num = num * 10 % den;
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}