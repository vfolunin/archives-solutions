#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    while (1) {
        n = (n + 8) / 9;
        if (n <= 1) {
            cout << "Stan wins.\n";
            return 1;
        }

        n = (n + 1) / 2;
        if (n <= 1) {
            cout << "Ollie wins.\n";
            return 1;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}