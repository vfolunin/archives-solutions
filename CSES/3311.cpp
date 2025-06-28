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
            if ((y + x) % 2)
                a[y][x] = 'A' + (a[y][x] == 'A');
            else
                a[y][x] = 'C' + (a[y][x] == 'C');
        }
    }

    for (string &s : a)
        cout << s << "\n";
}