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

    long long res = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res += (h - y) * (w - x);

    cout << res;
}