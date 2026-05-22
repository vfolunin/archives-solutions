#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    int res = 0;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int cur = y * size + x + 1;
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                if (0 <= ty && ty < size && 0 <= tx && tx < size)
                    cur += ty * size + tx + 1;
            }
            res = max(res, cur);
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}