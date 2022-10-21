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

    int h, w, y, x;
    cin >> h >> w >> y >> x;

    if (h > w)
        swap(h, w);

    cout << min({ y, x, h - y, w - x });
}