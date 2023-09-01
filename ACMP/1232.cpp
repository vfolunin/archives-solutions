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
    vector<int> rowSum(h), colSum(w);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            rowSum[y] += a[y][x];
            colSum[x] += a[y][x];
        }
    }

    for (int &sum : rowSum)
        cout << sum << " ";
    cout << "\n";

    for (int &sum : colSum)
        cout << sum << " ";
    cout << "\n";

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}