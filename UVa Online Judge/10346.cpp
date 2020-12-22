#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool solve() {
    long long n, k;
    if (!(cin >> n >> k))
        return 0;

    long long cigarettes = n, butts = n;
    while (butts >= k) {
        cigarettes += butts / k;
        butts = butts / k + butts % k;
    }

    cout << cigarettes << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}