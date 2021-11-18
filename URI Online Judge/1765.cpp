#include <iostream>
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

    for (int test = 1; test <= n; test++) {
        double k, a, b;
        cin >> k >> a >> b;

        cout << "Size #" << test << ":\n";
        cout.precision(2);
        cout << "Ice Cream Used: " << fixed << k * (a + b) * 2.5 << " cm2\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}