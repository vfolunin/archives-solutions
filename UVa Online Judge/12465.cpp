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

    long long diff = abs(a - b);
    long long divisorCount = 0;
    for (long long d = 1; d * d <= diff; d++) {
        if (diff % d)
            continue;
        divisorCount++;
        if (d * d != diff)
            divisorCount++;
    }

    cout << divisorCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}