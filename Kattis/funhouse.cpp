#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int w, h;
    cin >> w >> h;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    int curY, curX, curD;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '*') {
                curY = y;
                curX = x;
                if (y == h - 1)
                    curD = 0;
                else if (x == 0)
                    curD = 1;
                else if (y == 0)
                    curD = 2;
                else
                    curD = 3;
            }
        }
    }

    do {
        curY += dy[curD];
        curX += dx[curD];

        if (a[curY][curX] == '/')
            curD ^= 1;
        else if (a[curY][curX] == '\\')
            curD = 3 - curD;
    } while (a[curY][curX] != 'x');

    a[curY][curX] = '&';
    
    cout << "HOUSE " << test << "\n";
    for (string &s : a)
        cout << s << "\n";
    return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}