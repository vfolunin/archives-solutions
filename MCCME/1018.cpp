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

    vector<string> a(8, string(8, '.'));
    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++) {
            if (y % 2 == x % 2) {
                if (y <= 2)
                    a[y][x] = 'w';
                else if (y <= 4)
                    a[y][x] = '-';
                else
                    a[y][x] = 'b';
            }
        }
    }

    int moveCount;
    cin >> moveCount;

    for (int i = 0; i < moveCount; i++) {
        string s;
        cin >> s;

        for (int j = 4; j < s.size(); j += 3) {
            char y1 = s[j - 3] - '1', x1 = s[j - 4] - 'a';
            char y2 = s[j] - '1', x2 = s[j - 1] - 'a';
            char dy = y1 < y2 ? 1 : -1, dx = x1 < x2 ? 1 : -1;

            char c = a[y1][x1];
            if (c == 'w' && y2 == 7)
                c = 'W';
            if (c == 'b' && y2 == 0)
                c = 'B';

            while (y1 != y2) {
                a[y1][x1] = '-';
                y1 += dy;
                x1 += dx;
            }
            a[y2][x2] = c;
        }
    }

    for (int y = 7; y >= 0; y--)
        cout << a[y] << "\n";
}