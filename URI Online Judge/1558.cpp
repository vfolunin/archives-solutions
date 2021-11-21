#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    for (int a = 0; a * a <= n; a++) {
        for (int b = 0; a * a + b * b <= n; b++) {
            if (a * a + b * b == n) {
                cout << "YES\n";
                return 1;
            }
        }
    }

    cout << "NO\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}