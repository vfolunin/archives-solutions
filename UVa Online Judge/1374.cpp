#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(int powers[], int step, int depth, int target) {
    if (powers[step - 1] == target)
        return 1;

    if (step > depth)
        return 0;

    if (powers[step - 1] * (1 << (depth - step + 1)) < target)
        return 0;

    for (int i = step - 1; i >= 0; i--) {
        powers[step] = powers[i] + powers[step - 1];
        if (rec(powers, step + 1, depth, target))
            return 1;

        powers[step] = powers[i] - powers[step - 1];
        if (powers[step] >= 0 && rec(powers, step + 1, depth, target))
            return 1;

        powers[step] = powers[step - 1] - powers[i];
        if (powers[step] >= 0 && rec(powers, step + 1, depth, target))
            return 1;
    }
    return 0;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int powers[1000] = { 1 };

    int depth = 0;
    while (!rec(powers, 1, depth, n))
        depth++;

    cout << depth << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}