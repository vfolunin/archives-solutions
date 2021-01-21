#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool bfs(vector<string> &a, int y, int x) {
    bool res = a[y][x] == 'x';

    a[y][x] = '.';
    queue<int> q;
    q.push(y);
    q.push(x);    

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };
    
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && a[ty][tx] != '.') {
                res |= a[ty][tx] == 'x';
                a[ty][tx] = '.';
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return res;
}

void solve(int test) {
    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    int res = 0;
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            if (a[y][x] != '.')
                res += bfs(a, y, x);    

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}