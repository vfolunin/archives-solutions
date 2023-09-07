#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long floorCount, mod, a, b, queryCount;
    cin >> floorCount >> mod >> a >> b >> queryCount;

    long long flatsPerEntrance = floorCount / mod * a + (floorCount - floorCount / mod) * b;

    for (int i = 0; i < queryCount; i++) {
        long long flat;
        cin >> flat;

        flat = (flat - 1) % flatsPerEntrance;

        long long l = 0, r = floorCount;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (m / mod * a + (m - m / mod) * b <= flat)
                l = m;
            else
                r = m;
        }

        cout << r << "\n";
    }
}