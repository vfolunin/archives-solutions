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

    char x, y;
    cin >> x >> y;
    x -= 'a';
    y -= '1';

    vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
    int res = 0;

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        res += 0 <= ty && ty < 8 && 0 <= tx && tx < 8;
    }

    cout << res;
}