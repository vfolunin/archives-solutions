#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (!n)
        return 0;

    cout << n / a + n / b - n / lcm(a, b) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}