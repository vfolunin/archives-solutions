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

    int size, attackedCount;
    cin >> size >> attackedCount;

    vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };
    int res = 0;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int curAttackedCount = 0;
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                curAttackedCount += 0 <= ty && ty < size && 0 <= tx && tx < size;
            }
            res += curAttackedCount == attackedCount;
        }
    }

    cout << res;
}