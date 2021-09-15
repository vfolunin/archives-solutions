#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double targetSum;
    cin >> targetSum;

    if (!targetSum)
        return 0;

    double sum = 0;
    int res;
    for (res = 2; sum < targetSum; res++)
        sum += 1.0 / res;

    cout << res - 2 << " card(s)\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}