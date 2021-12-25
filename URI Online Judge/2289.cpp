#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    unsigned long long a, b;
    cin >> a >> b;

    if (!a && !b)
        return 0;

    unsigned long long x = a ^ b;
    int ones = 0;
    while (x) {
        ones++;
        x &= x - 1;
    }

    cout << ones << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}