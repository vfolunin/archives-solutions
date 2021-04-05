#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    vector<string> mines(size);
    for (string &row : mines)
        cin >> row;

    vector<string> open(size);
    for (string &row : open)
        cin >> row;

    bool blown = 0;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (open[y][x] == 'x') {
                if (mines[y][x] == '*') {
                    blown = 1;
                } else {
                    open[y][x] = '0';

                    static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
                    static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

                    for (int d = 0; d < 8; d++) {
                        int ty = y + dy[d], tx = x + dx[d];
                        if (0 <= ty && ty < size && 0 <= tx && tx < size && mines[ty][tx] == '*')
                            open[y][x]++;
                    }
                }
            }
        }
    }

    if (blown)
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
                if (mines[y][x] == '*')
                    open[y][x] = '*';

    if (test)
        cout << "\n";
    for (string &row : open)
        cout << row << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}