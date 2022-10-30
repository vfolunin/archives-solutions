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

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int fromX = 0, value = 0; fromX < w + h; fromX++)
        for (int y = 0, x = fromX; y < h; y++, x--)
            if (0 <= y && y < h && 0 <= x && x < w)
                a[y][x] = value++;
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}