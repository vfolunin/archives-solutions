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

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '.' && (!y || a[y - 1][x] == '#') && (!x || a[y][x - 1] == '#') &&
                (y + 1 == h || a[y + 1][x] == '#') && (x + 1 == w || a[y][x + 1] == '#'))
                a[y][x] = 'E';
        }
    }

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] == '.' && (y + x) % 2)
                a[y][x] = 'E';

    for (string &s : a)
        cout << s << "\n";
}