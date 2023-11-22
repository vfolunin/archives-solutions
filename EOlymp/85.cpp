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

    int size, targetY, targetX;
    cin >> size >> targetY >> targetX;

    vector<vector<int>> a(size, vector<int>(size));

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    for (int y = 0, x = 0, d = 1, value = 1; value <= a.size() * a.size(); value++) {
        a[y][x] = value;
        for (int i = 0; i < dy.size(); i++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && !a[ty][tx]) {
                y = ty;
                x = tx;
                break;
            } else {
                d = (d + 1) % dy.size();
            }
        }
    }

    cout << a[targetY - 1][targetX - 1];
}