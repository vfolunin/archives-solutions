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

    while (1) {
        bool updated = 0;

        for (int y = 1; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y - 1][x] == 'V' && a[y][x] == '.') {
                    a[y][x] = 'V';
                    updated = 1;
                }

                if (a[y - 1][x] == 'V' && a[y][x] == '#') {
                    if (x && a[y - 1][x - 1] == '.') {
                        a[y - 1][x - 1] = 'V';
                        updated = 1;
                    }
                    if (x + 1 < w && a[y - 1][x + 1] == '.') {
                        a[y - 1][x + 1] = 'V';
                        updated = 1;
                    }
                }
            }
        }

        if (!updated)
            break;
    }

    for (string &s : a)
        cout << s << "\n";
}