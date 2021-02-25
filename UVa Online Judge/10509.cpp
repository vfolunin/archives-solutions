#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double x;
    cin >> x;

    if (!x)
        return 0;

    double a = 0;
    while (a * a * a <= x)
        a++;
    a--;

    double dx = (x - a * a * a) / (3 * a * a);

    cout.precision(4);
    cout << fixed << a + dx << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}