#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<string> &a, int y, int x) {
    a[y][x] = 'I';
    int res = 1;

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != 'I')
            res += dfs(a, ty, tx);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count, h, w;
    cin >> count >> h >> w;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    vector<int> rooms;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] != 'I')
                rooms.push_back(dfs(a, y, x));

    sort(rooms.rbegin(), rooms.rend());

    int res = 0;
    while (res < rooms.size() && count >= rooms[res])
        count -= rooms[res++];

    cout << res << " room" << (res == 1 ? "" : "s") << ", " << count << " square metre(s) left over";
}