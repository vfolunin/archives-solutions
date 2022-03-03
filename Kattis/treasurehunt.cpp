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
    for (string &row : a)
        cin >> row;

    int y = 0, x = 0, stepCount = 0;
    while (1) {
        if (y < 0 || y >= h || x < 0 || x >= w) {
            cout << "Out";
            break;
        }
        if (a[y][x] == '#') {
            cout << "Lost";
            break;
        }
        if (a[y][x] == 'T') {
            cout << stepCount;
            break;
        }

        char d = a[y][x];
        a[y][x] = '#';

        if (d == 'N')
            y--;
        else if (d == 'S')
            y++;
        else if (d == 'W')
            x--;
        else if (d == 'E')
            x++;

        stepCount++;
    }
}