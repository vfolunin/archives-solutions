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

    int w, h;
    cin >> w >> h;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    string dc = "^>v<";
    int dy[] = { -1, 0, 1, 0 };
    int dx[] = { 0, 1, 0, -1 };

    int y = 0, x = 0, d = -1;
    while (1) {
        if (a[y][x] == '*') {
            cout << "*\n";
            break;
        }
        if (y < 0 || y >= h || x < 0 || x >= w || a[y][x] == '#') {
            cout << "!\n";
            break;
        }

        if (a[y][x] != '.')
            d = dc.find(a[y][x]);
        
        a[y][x] = '#';
        y += dy[d];
        x += dx[d];
    }
}