#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double a, b;
    if (!(cin >> a >> b))
        return 0;

    int n = a;
    a -= n;
    n += a > b;

    cout << n << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}