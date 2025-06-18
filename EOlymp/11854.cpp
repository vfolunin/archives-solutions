#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int sum;
    cin >> sum;

    for (int a = 1; a < 10; a++) {
        if (a % 4 == 0)
            continue;
        for (int b = a + 1; b < 10; b++) {
            if (b % 4 == 0)
                continue;
            for (int c = b + 1; c < 10; c++) {
                int d = sum - a - b - c;
                if (0 < d && c % 4 && d % 4 && a != d && b != d && c != d) {
                    cout << a << " " << b << " " << c << " " << d << "\n";
                    return;
                }
            }
        }
    }

    cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
        solve();
}