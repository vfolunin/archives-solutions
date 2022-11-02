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
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    cout << w << " " << h << "\n";
    
    for (int x = 0; x < w; x++) {
        for (int y = h - 1; y >= 0; y--)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}