#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a += (t + 30) / 30 * 10;
        b += (t + 60) / 60 * 15;
    }

    cout << "Case " << test << ": ";
    if (a <= b)
        cout << "Mile ";
    if (b <= a)
        cout << "Juice ";
    cout << min(a, b) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}