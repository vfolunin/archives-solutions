#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b, c, kac, kcb, kba, n;
    if (!(cin >> a >> b >> c >> kac >> kcb >> kba >> n))
        return 0;

    for (int i = 0; i < n; i++) {
        int na = b / kba;
        int nb = c / kcb;
        int nc = a * kac;
        a = na;
        b = nb;
        c = nc;
    }

    cout << a << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}