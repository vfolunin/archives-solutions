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

    int h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    vector<string> a(h1, string(w1, '+'));
    for (int y = 1; y <= h2; y++)
        for (int x = 1; x <= w2; x++)
            a[y][x] = '-';

    for (string &s : a)
        cout << s << "\n";
}