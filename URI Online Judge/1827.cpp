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

    int w = n / 2 - n / 3;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n / 2 && j == n / 2)
                cout << 4;
            else if (abs(i - n / 2) <= w && abs(j - n / 2) <= w)
                cout << 1;
            else if (i == j)
                cout << 2;
            else if (i + j == n - 1)
                cout << 3;
            else
                cout << 0;
        }
        cout << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}