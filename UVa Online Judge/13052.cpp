#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int a, b;
    cin >> a >> b;

    if (!a && !b)
        cout << "Case " << test << ": 0.000 0.000\n";
    else if (b % 2)
        cout << "Case " << test << ": 0.000 1.000\n";
    else
        cout << "Case " << test << ": 1.000 0.000\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}