#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int w = to_string(1 << (2 * n - 2)).size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << setw(w) << (1 << (i + j)) << (j + 1 < n ? " " : "\n");

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}