#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int h, int w, int mask) {
    vector<int> ways(1 << (h * w));
    queue<int> q;

    ways[mask] = 1;
    q.push(mask);

    while (!q.empty()) {
        int mask = q.front();
        q.pop();
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!(mask & (1 << (y * w + x))))
                    continue;

                int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
                int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

                for (int d = 0; d < 8; d++) {
                    int t1y = y + dy[d], t2y = t1y + dy[d];
                    int t1x = x + dx[d], t2x = t1x + dx[d];

                    if (0 <= t2y && t2y < h && 0 <= t2x && t2x < w &&
                        (mask & (1 << (t1y * w + t1x))) && !(mask & (1 << (t2y * w + t2x)))) {
                        int tMask = mask ^ (1 << (y * w + x)) ^ (1 << (t1y * w + t1x)) ^ (1 << (t2y * w + t2x));
                        if (ways[tMask] == 0) {
                            ways[tMask] = ways[mask];
                            q.push(tMask);
                        } else {
                            ways[tMask] += ways[mask];
                        }
                    }
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < h * w; i++)
        res += ways[1 << i];

    return res;
}

void solve(int test) {
    int h, w, blobCount;
    cin >> h >> w >> blobCount;

    int mask = 0;
    for (int i = 0; i < blobCount; i++) {
        int y, x;
        cin >> y >> x;
        y--;
        x--;
        mask |= (1 << (y * w + x));
    }

    cout << "Case " << test << ": " << bfs(h, w, mask) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}