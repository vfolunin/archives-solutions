#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitCount(int n) {
    int res = 1;
    while (n > 9) {
        res++;
        n /= 10;
    }
    return res;
}

bool solve() {
    string s;
    cin >> s;

    if (s == "END")
        return 0;

    if (s == "1") {
        cout << "1\n";
        return 1;
    }

    int n = s.size(), res = 2;
    while (n > 1) {
        n = digitCount(n);
        res++;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}