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

    char x, y;
    cin >> x >> y;
    x -= 'a';
    y -= '1';

    for (int ry = 0; ry < 8; ry++) {
        for (int rx = 0; rx < 8; rx++) {
            if (ry != y && rx != x)
                continue;

            for (int by = 0; by < 8; by++) {
                for (int bx = 0; bx < 8; bx++) {
                    if (ry == by || rx == bx ||
                        ry + rx == by + bx || ry - rx == by - bx ||
                        by + bx != y + x && by - bx != y - x)
                        continue;

                    cout << (char)(rx + 'a') << (char)(ry + '1') << "\n";
                    cout << (char)(bx + 'a') << (char)(by + '1');
                    return 0;
                }
            }
        }
    }
}