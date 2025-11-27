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
    for (string &s : a)
        cin >> s;

    vector<string> res(2 * h, string(2 * w, ' '));
    for (int y = 0; y < res.size(); y++)
        for (int x = 0; x < res[0].size(); x++)
            res[y][x] = a[y < a.size() ? y : a.size() * 2 - 1 - y][x < a[0].size() ? x : a[0].size() * 2 - 1 - x];

    int y, x;
    cin >> y >> x;
    y--;
    x--;

    res[y][x] = '.' + '#' - res[y][x];

    for (string &s : res)
        cout << s << "\n";
}