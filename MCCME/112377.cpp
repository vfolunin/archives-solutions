#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int index = 1, diag = 0; index <= h * w; diag++) {
        if (diag % 2) {
            for (int y = diag, x = 0; 0 <= y && x < w && index <= h * w; y--, x++)
                if (y < h)
                    a[y][x] = index++;
        } else {
            for (int y = 0, x = diag; y < h && 0 <= x && index <= h * w; y++, x--)
                if (x < w)
                    a[y][x] = index++;
        }
    }
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}