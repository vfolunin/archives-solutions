#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        double x, y;
        cin >> x >> y;

        count += hypot(x, y) > 0.5;
    }

    cout << (count < 700 ? "1\n" : "2\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 100; i++)
        solve();
}