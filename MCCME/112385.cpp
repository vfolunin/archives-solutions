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
    double mean = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            mean += a[y][x];
        }
    }

    mean /= h * w;

    cout.precision(4);
    cout << fixed << mean << "\n";

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << (a[y][x] < mean ? 0 : 255) << " ";
        cout << "\n";
    }
}