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

    int size, x1, h1, x2, h2, queryCount;
    cin >> size >> x1 >> h1 >> x2 >> h2 >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int x, t;
        cin >> x >> t;

        int h = max(h1 - abs(x - x1), 0) + max(h2 - abs(x - x2), 0);

        cout << (h >= t ? h - t + 1 : 0) << "\n";
    }
}