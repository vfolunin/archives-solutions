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

    int size, h, w;
    cin >> size >> h >> w;

    vector<vector<string>> a(h, vector<string>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            string s;
            cin >> s;

            if (!x)
                cout << (a[y][x] == s ? "left\n" : "right\n");
        }
    }
}