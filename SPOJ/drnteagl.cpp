#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int pointCount;
    cin >> pointCount;

    int resDist = -1, resI;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        int dist = x * x + y * y;
        if (resDist < dist) {
            resDist = dist;
            resI = i;
        }
    }

    cout << "Case " << test << ": " << resI + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}