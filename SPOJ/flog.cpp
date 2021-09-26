#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    double base, n;
    cin >> base >> n;

    cout << "Case " << test << ": ";

    if (base <= 1 || n == 0) {
        cout << "Math Error!\n";
    } else {
        cout.precision(5);
        cout << fixed << log(n) / log(base) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int test = 1; test <= n; test++)
        solve(test);
}