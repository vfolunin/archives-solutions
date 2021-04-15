#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int code(string &word) {
    int res = 0;
    for (char c : word)
        res = res * 32 + c - 'a' + 1;
    return res;
}

bool solve() {
    int base, lastDigit, factor;
    if (!(cin >> base >> lastDigit >> factor))
        return 0;

    int digit = lastDigit, over = 0, res = 0;
    while (1) { 
        int prod = digit * factor + over;
        over = prod / base;
        digit = prod % base;
        res++;
        if (digit == lastDigit && !over)
            break;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}