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

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<int> res(5);
    for (int y = 0; y + 1 < h; y++) {
        for (int x = 0; x + 1 < w; x++) {
            string place = string(1, a[y][x]) + a[y][x + 1] + a[y + 1][x] + a[y + 1][x + 1];
            if (place.find('#') == -1)
                res[count(place.begin(), place.end(), 'X')]++;
        }
    }

    for (int r : res)
        cout << r << "\n";
}