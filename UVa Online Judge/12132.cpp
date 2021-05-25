#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<int> cy(h * w, -1), cx(h * w, -1);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;
            if (value > 0) {
                cy[value - 1] = y;
                cx[value - 1] = x;
            }
        }
    }

    vector<int> shift(h);
    long long res = 0;
    for (int i = 0; i < h * w && cy[i] != -1; i++) {
        res += 2 * cy[i] * 10;

        int cw = (shift[cy[i]] <= cx[i] ? 0 : w) + cx[i] - shift[cy[i]];
        int ccw = w - cw;

        if (cw <= ccw) {
            res += cw * 5;
            shift[cy[i]] = (shift[cy[i]] + cw) % w;
        } else {
            res += ccw * 5;
            shift[cy[i]] = (shift[cy[i]] + w - ccw) % w;
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}