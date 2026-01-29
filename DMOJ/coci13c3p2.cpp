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

    int h, w, u, l, r, d;
    cin >> h >> w >> u >> l >> r >> d;

    vector<string> text(h);
    for (string &row : text)
        cin >> row;

    for (int y = 0; y < u + h + d; y++) {
        for (int x = 0; x < l + w + r; x++) {
            if (y < u || y >= u + h || x < l || x >= l + w)
                cout << ((x + y) % 2 ? "." : "#");
            else
                cout << text[y - u][x - l];
        }
        cout << "\n";
    }
}