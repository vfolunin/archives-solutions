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

    vector<string> a(5);
    for (string &row : a)
        cin >> row;

    int knightCount = 0;

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++) {
            if (a[y][x] != 'k')
                continue;

            knightCount++;

            static int dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
            static int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

            for (int d = 0; d < 8; d++) {
                int ty = y + dy[d], tx = x + dx[d];
                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && a[ty][tx] == 'k') {
                    cout << "invalid";
                    return 0;
                }
            }
        }
    }
    
    cout << (knightCount == 9 ? "valid" : "invalid");
}