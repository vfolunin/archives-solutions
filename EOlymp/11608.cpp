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

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    vector<int> dy = { -1, 0, 1, 1 };
    vector<int> dx = { 1, 1, 1, 0 };
    int res = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int d = 0; d < dy.size(); d++) {
                string s;
                for (int step = 0; step < 4; step++) {
                    int ty = y + dy[d] * step;
                    int tx = x + dx[d] * step;
                    if (0 <= ty && ty < h && tx < w)
                        s += a[ty][tx];
                }
                res += s == "saba";
            }
        }
    }

    cout << res;
}