#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int h, w;
    cin >> h >> w;

    if (!h)
        return 0;

    vector<string> a(h);
    for (string &s : a) {
        cin >> s;

        for (char &c : s)
            if (c == '.')
                c = '0';
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] != '*')
                continue;

            static vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
            static vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != '*')
                    a[ty][tx]++;
            }
        }
    }

    cout << "Field #" << test << ":\n";
    for (string &s : a)
        cout << s << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}