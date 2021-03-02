#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int leapsTo(int y) {
    return y / 4 - y / 100 + y / 400;
}

void solve(int test) {
    int d, m, y1, y2;
    cin >> d >> m >> y1 >> y2;

    cout << "Case " << test << ": ";
    if (d != 29 || m != 2)
        cout << y2 - y1 << "\n";
    else
        cout << leapsTo(y2) - leapsTo(y1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}