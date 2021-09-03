#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aSize, bSize;
    cin >> aSize >> bSize;

    if (!aSize)
        return 0;

    vector<string> a(aSize);
    int aDots = 0;
    for (string &row : a) {
        cin >> row;
        aDots += count(row.begin(), row.end(), '*');
    }

    vector<string> b(bSize);
    int bDots = 0;
    for (string &row : b) {
        cin >> row;
        bDots += count(row.begin(), row.end(), '*');
    }

    if (aDots != bDots * 2) {
        cout << "0\n";
        return 1;
    }

    for (int y1 = 1 - bSize; y1 < aSize; y1++) {
        for (int x1 = 1 - bSize; x1 < aSize; x1++) {
            for (int y2 = 1 - bSize; y2 < aSize; y2++) {
                for (int x2 = 1 - bSize; x2 < aSize; x2++) {

                    bool ok = 1;
                    for (int y = 0; ok && y < aSize; y++) {
                        for (int x = 0; ok && x < aSize; x++) {
                            int yy1 = y - y1, xx1 = x - x1;
                            int dot1 = 0 <= yy1 && yy1 < bSize && 0 <= xx1 && xx1 < bSize && b[yy1][xx1] == '*';

                            int yy2 = y - y2, xx2 = x - x2;
                            int dot2 = 0 <= yy2 && yy2 < bSize && 0 <= xx2 && xx2 < bSize && b[yy2][xx2] == '*';

                            ok &= a[y][x] == '.' && dot1 + dot2 == 0 || a[y][x] == '*' && dot1 + dot2 == 1;
                        }
                    }

                    if (ok) {
                        cout << "1\n";
                        return 1;
                    }

                }
            }
        }
    }

    cout << "0\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}