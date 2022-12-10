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

    int w, h;
    cin >> w >> h;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<string> b(h);
    for (string &row : b)
        cin >> row;

    string op;
    cin >> op;

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            a[y][x] = op[(a[y][x] - '0') * 2 + (b[y][x] - '0')];

    for (string row : a)
        cout << row << "\n";
}