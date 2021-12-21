#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool solve() {
    int n, a, b, c;
    if (!(cin >> n >> a >> b >> c))
        return 0;

    cout << lcm(a, lcm(b, c)) - n << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}