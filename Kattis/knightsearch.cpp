#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(vector<string> &a, int y, int x, const string &s, int i) {
    if (a[y][x] != s[i])
        return 0;
    if (i == s.size() - 1)
        return 1;

    static int dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
    static int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

    for (int d = 0; d < 8; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && rec(a, ty, tx, s, i + 1))
            return 1;
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size, string(size, ' '));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (rec(a, y, x, "ICPCASIASG", 0)) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}