#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
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

    int res = 0;
    for (int y = 0; y + 1 < h; y++)
        for (int x = 0; x + 1 < w; x++)
            res += unordered_set<char>{ a[y][x], a[y][x + 1], a[y + 1][x], a[y + 1][x + 1] } ==
                   unordered_set<char>{ 'c', 's', 'a', 'u' };
    
    cout << res;
}