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

    int w, h, stickerCount;
    cin >> w >> h >> stickerCount;

    vector<string> res(h, string(w, '_'));

    for (int i = 0; i < stickerCount; i++) {
        int sw, sh, sx, sy;
        cin >> sw >> sh >> sx >> sy;

        for (int y = 0; y < sh && sy + y < h; y++)
            for (int x = 0; x < sw && sx + x < w; x++)
                res[sy + y][sx + x] = i + 'a';
    }

    for (string &s : res)
        cout << s << "\n";
}