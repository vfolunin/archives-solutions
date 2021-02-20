#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    if (!a && !b && !c && !d && !e)
        return 0;

    cout << a * b * c * d * d * e * e << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}