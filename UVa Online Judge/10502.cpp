#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int height;
    cin >> height;

    if (!height)
        return 0;

    int width;
    cin >> width;

    vector<vector<int>> p(height, vector<int>(width));

    for (int i = 0; i < height; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < width; j++) {
            p[i][j] = (s[j] == '1');
            if (i)
                p[i][j] += p[i - 1][j];
        }
    }

    int res = 0;
    for (int y1 = 0; y1 < height; y1++) {
        for (int y2 = y1; y2 < height; y2++) {
            int cur = 0;
            for (int x = 0; x < width; x++) {
                if (p[y2][x] - (y1 ? p[y1 - 1][x] : 0) == y2 - y1 + 1)
                    cur++;
                else
                    cur = 0;
                res += cur;
            }
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}