#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b;
    cin >> a >> b;

    if (!a && !b)
        return 0;

    if (a < b)
        swap(a, b);

    int res = 1;
    while (a / b <= 1 && a % b) {
        int na = b, nb = a % b;
        a = na;
        b = nb;
        res = 3 - res;
    }

    cout << (res == 1 ? "Stan" : "Ollie") << " wins\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}