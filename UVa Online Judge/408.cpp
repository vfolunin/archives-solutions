#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    int step, mod;
    if (!(cin >> step >> mod))
        return 0;

    cout << setw(10) << step << setw(10) << mod << "    ";
    cout << (gcd(step, mod) == 1 ? "Good" : "Bad") << " Choice\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}