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

    static string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    cout << 2 << " " << n << " " << n << "\n";
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++)
            cout << letters[y];
        cout << "\n";
    }
    cout << "\n";
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++)
            cout << letters[x];
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}