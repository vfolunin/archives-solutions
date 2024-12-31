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

    int h, w, factor;
    cin >> h >> w >> factor;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    for (int y = 0; y < h * factor; y++) {
        for (int x = 0; x < w * factor; x++)
            cout << a[y / factor][x / factor];
        cout << "\n";
    }
}