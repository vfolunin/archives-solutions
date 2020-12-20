#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void solve(int test, int h, int w) {
    vector<string> field(h);
    for (string &row : field)
        cin >> row;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (field[i][j] == '*')
                continue;

            field[i][j] = '0';
            for (int ti = i - 1; ti <= i + 1; ti++)
                for (int tj = j - 1; tj <= j + 1; tj++)
                    if (0 <= ti && ti < h && 0 <= tj && tj < w && field[ti][tj] == '*')
                        field[i][j]++;
        }
    }

    if (test > 1)
        cout << "\n";
    cout << "Field #" << test << ":\n";
    for (string &row : field)
        cout << row << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; 1; test++) {
        int h, w;
        cin >> h >> w;
        if (!h || !w)
            break;
        solve(test, h, w);
    }
}