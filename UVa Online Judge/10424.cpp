#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int getDigitRoot(int x) {
    if (x < 10)
        return x;
    int r = 0;
    while (x) {
        r += x % 10;
        x /= 10;
    }
    return getDigitRoot(r);
}

int getRes(string &s) {
    int sum = 0;
    for (char c : s)
        if (isalpha(c))
            sum += c - (isupper(c) ? 'A' : 'a') + 1;
    return getDigitRoot(sum);
}

bool solve() {
    string a, b;
    if (!getline(cin, a))
        return 0;
    getline(cin, b);

    int ra = getRes(a), rb = getRes(b);
    if (ra > rb)
        swap(ra, rb);

    cout.precision(2);
    cout << fixed << 100.0 * ra / rb << " %\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}