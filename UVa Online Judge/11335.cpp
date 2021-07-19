#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long solve(long long x, long long v) {
    long long cx = 1, cv = 2, t = 1;
    while (cx < x) {
        cx += cv;
        cv++;
        x += v;
        t++;
    }
    return t;
}

bool solve() {
    long long x, vx, vy;
    if (!(cin >> x >> vx >> vy))
        return 0;

    cout << (x ? max(solve(x + vx, vx), solve(vy, vy)) : 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}