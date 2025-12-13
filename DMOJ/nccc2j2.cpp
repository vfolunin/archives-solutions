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

    for (int i = 0; i < 100; i++)
        for (int y = 0; y + 1 < h; y++)
            for (int x = 0; x < w; x++)
                if (a[y][x] == 'o' && a[y + 1][x] == '.')
                    swap(a[y][x], a[y + 1][x]);
    
    for (string &s : a)
        cout << s << "\n";
}