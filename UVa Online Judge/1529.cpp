#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h1, m1, h2, m2;
    if (scanf("%d%d%d%d", &h1, &m1, &h2, &m2) != 4)
        return 0;

    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;
    if (t2 < t1)
        t2 += 12 * 60;

    vector<double> eqTime;
    for (int i = 0; i < 60; i++)
        eqTime.push_back(720.0 * i / 11);

    int res = 0;
    for (int t = t1; t < t2; t++) {
        auto it = lower_bound(eqTime.begin(), eqTime.end(), t);
        res += t < *it && *it <= t + 1;
    }

    printf("       %02d:%02d       %02d:%02d %7d\n", h1, m1, h2, m2, res);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    printf("Program 3 by team X\n");
    printf("Initial time  Final time  Passes\n");
    while (solve());
    printf("End of program 3 by team X\n");
}