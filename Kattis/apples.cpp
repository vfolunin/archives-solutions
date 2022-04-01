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

    for (int x = 0; x < w; x++) {
        int from = 0, emptyCount = 0, appleCount = 0;
        for (int y = 0; y < h; y++) {
            if (a[y][x] == '.') {
                emptyCount++;
            } else if (a[y][x] == 'a') {
                appleCount++;
            } else {
                for (int i = 0; i < emptyCount; i++)
                    a[from + i][x] = '.';
                for (int i = 0; i < appleCount; i++)
                    a[from + emptyCount + i][x] = 'a';
                from = y + 1;
                emptyCount = appleCount = 0;
            }
        }
        for (int i = 0; i < emptyCount; i++)
            a[from + i][x] = '.';
        for (int i = 0; i < appleCount; i++)
            a[from + emptyCount + i][x] = 'a';
    }

    for (string &row : a)
        cout << row << "\n";
}