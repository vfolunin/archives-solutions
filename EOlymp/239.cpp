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

    int pointCount;
    cin >> pointCount;

    vector<long long> count(4);
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        count[abs(x) % 2 * 2 + abs(y) % 2]++;
    }

    long long res = 0;
    for (int a = 0; a < count.size(); a++) {
        int ax = a / 2, ay = a % 2;
        for (int b = a; b < count.size(); b++) {
            int bx = b / 2, by = b % 2;
            for (int c = b; c < count.size(); c++) {
                int cx = c / 2, cy = c % 2;

                if (((ax - bx) * (ay - cy) - (ax - cx) * (ay - by)) % 2)
                    continue;

                if (a == b && a == c)
                    res += count[a] * (count[b] - 1) * (count[c] - 2) / 6;
                else if (a == b)
                    res += count[a] * (count[b] - 1) * count[c] / 2;
                else if (a == c || b == c)
                    res += count[a] * count[b] * (count[c] - 1) / 2;
                else
                    res += count[a] * count[b] * count[c];
            }
        }
    }

    cout << res;
}