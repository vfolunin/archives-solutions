#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long h, w, cutCount, partCount;
    cin >> h >> w >> cutCount >> partCount;

    long long a = 1, b = -cutCount, c = partCount - cutCount - 1;
    long long d = b * b - 4 * a * c;

    if (d >= 0) {
        long long root = sqrt(d);
        if (root * root == d) {
            long long x1 = (-b - root) / (2 * a);
            long long x2 = (-b + root) / (2 * a);
            
            if (x1 > x2)
                swap(x1, x2);

            for (long long x : { x1, x2 }) {
                if (x < h && cutCount - x < w) {
                    cout << x << " " << cutCount - x << "\n";
                    return;
                }
            }
        }
    }

    cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}