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

    vector<vector<int>> a(w, vector<int>(h));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[x][y];

    for (vector<int> &row : a)
        sort(row.rbegin(), row.rend());

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << a[x][y] << " ";
        cout << "\n";
    }
}