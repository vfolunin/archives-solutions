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

    char y, x;
    cin >> x >> y;
    x -= 'a';
    y = '8' - y;

    vector<string> a(8, string(8, '.'));
    a[y][x] = 'K';

    vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size())
            a[ty][tx] = '*';
    }

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}