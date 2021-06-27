#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    long long limit = 3e6;
    for (long long x = 1, y = 1; y < limit; y++) {
        while (x * x * x - y * y * y < n)
            x++;
        if (x * x * x - y * y * y == n) {
            cout << x << " " << y << "\n";
            return 1;
        }
    }

    cout << "No solution\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}