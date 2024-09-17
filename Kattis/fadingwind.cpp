#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, k, v, s;
    cin >> h >> k >> v >> s;

    int res = 0;
    while (h > 0) {
        v += s;
        v -= max(1, v / 10);
        h += v >= k;
        if (0 < v && v < k) {
            h--;
            if (h == 0)
                v = 0;
        }
        if (v <= 0)
            h = v = 0;
        res += v;
        s -= s > 0;
    }

    cout << res;
}