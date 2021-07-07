#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w, r, c;
    cin >> h >> w >> r >> c;

    if (!h && !w)
        return 0;

    vector<string> target(h);
    for (string &row : target)
        cin >> row;

    int res = 0;
    vector<string> pic(h, string(w, '0'));

    for (int i = 0; i + r <= h; i++) {
        for (int j = 0; j + c <= w; j++) {
            if (pic[i][j] != target[i][j]) {
                res++;
                for (int di = 0; di < r; di++)
                    for (int dj = 0; dj < c; dj++)
                        pic[i + di][j + dj] ^= 1;
            }
        }
    }

    cout << (pic == target ? res : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}