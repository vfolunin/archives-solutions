#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int l = 1, r = 10;
    while (1) {
        int guess;
        string res;
        if (!(cin >> guess >> res >> res))
            return 0;
        if (res == "low") {
            l = max(l, guess + 1);
        } else if (res == "high") {
            r = min(r, guess - 1);
        } else {
            if (l <= guess && guess <= r)
                cout << "Stan may be honest\n";
            else
                cout << "Stan is dishonest\n";
            return 1;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}