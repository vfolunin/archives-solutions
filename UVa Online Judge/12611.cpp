#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int r;
    cin >> r;
    r /= 4;

    cout << "Case " << test << ":\n";
    cout << -9 * r << " " << 6 * r << "\n";
    cout << 11 * r << " " << 6 * r << "\n";
    cout << 11 * r << " " << -6 * r << "\n";
    cout << -9 * r << " " << -6 * r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}