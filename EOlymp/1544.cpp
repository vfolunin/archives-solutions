#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    unsigned long long n;
    cin >> n;

    if (!n)
        return 0;

    for (int d = 9; d >= 0; d--)
        if ((n - d) % 9 == 0)
            cout << (n - d) / 9 * 10 + d << " ";

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}