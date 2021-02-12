#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    int tripletCount = 0;
    vector<bool> inTriplet(n + 1);

    for (int x = 1; x * x <= n; x++) {
        for (int y = x + 1; x * x + y * y <= n; y += 2) {
            if (gcd(x, y) == 1) {
                tripletCount++;
                int a = y * y - x * x;
                int b = 2 * x * y;
                int c = x * x + y * y;
                for (int i = 1; c * i <= n; i++)
                    inTriplet[a * i] = inTriplet[b * i] = inTriplet[c * i] = 1;
            }
        }
    }

    cout << tripletCount << " " << count(inTriplet.begin() + 1, inTriplet.end(), 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}