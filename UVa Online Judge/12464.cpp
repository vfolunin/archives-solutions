#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long a, b, n;
    cin >> a >> b >> n;

    if (!a && !b && !n)
        return 0;

    vector<long long> seq = { a, b, (1 + b) / a, (1 + a + b) / (a * b), (1 + a) / b };

    cout << seq[n % 5] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}