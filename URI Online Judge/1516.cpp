#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h1, w1;
    cin >> h1 >> w1;

    if (!h1 && !w1)
        return 0;

    vector<string> a(h1);
    for (string &row : a)
        cin >> row;

    int h2, w2;
    cin >> h2 >> w2;

    int kh = h2 / h1, kw = w2 / w1;

    for (int y = 0; y < h2; y++) {
        for (int x = 0; x < w2; x++)
            cout << a[y / kh][x / kw];
        cout << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}