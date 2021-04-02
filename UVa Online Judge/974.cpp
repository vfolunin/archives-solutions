#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int l, r;
    cin >> l >> r;

    static vector<int> kaprekar = {
        9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879,
        4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962
    };

    if (test > 1)
        cout << "\n";
    cout << "case #" << test << "\n";
    bool found = 0;
    for (int k : kaprekar) {
        if (l <= k && k <= r) {
            cout << k << "\n";
            found = 1;
        }
    }
    if (!found)
        cout << "no kaprekar numbers\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}