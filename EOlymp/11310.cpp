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

    int h, w, ky, kx;
    cin >> h >> w >> ky >> kx;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    for (int y = 0; y < ky * h; y++) {
        for (int x = 0; x < kx * w; x++)
            cout << a[y / ky][x / kx];
        cout << "\n";
    }
}