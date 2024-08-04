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

    int res = 0;
    for (int y = 0; y + 1 < h; y++) {
        for (int x = 0; x + 1 < w; x++) {
            int count = 0;
            for (int ty = y; ty < y + 2; ty++)
                for (int tx = x; tx < x + 2; tx++)
                    count += a[ty][tx] == 'X';

            if (count == 0)
                res += 4;
            else if (count == 1)
                res++;
        }
    }

    cout << res;
}