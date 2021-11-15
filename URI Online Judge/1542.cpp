#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double p1, d, p2;
    if (!(cin >> p1 >> d >> p2))
        return 0;

    int res = p1 * p2 * d / (p2 - p1);

    cout << res << " pagina" << (res > 1 ? "s" : "") << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}