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

    vector<string> a(7);
    for (string &row : a)
        getline(cin, row);

    int moveCount = 0;
    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++) {
            if (a[y][x] == 'o') {
                static int dy[] = { -1, 0, 1, 0 };
                static int dx[] = { 0, 1, 0, -1 };
                for (int d = 0; d < 4; d++) {
                    int ty = y + dy[d], tx = x + dx[d];
                    int ty2 = y + 2 * dy[d], tx2 = x + 2 * dx[d];
                    moveCount += 0 <= ty2 && ty2 < a.size() &&
                                 0 <= tx2 && tx2 < a.size() &&
                                 a[ty][tx] == 'o' && a[ty2][tx2] == '.';
                }
            }
        }
    }

    cout << moveCount;
}