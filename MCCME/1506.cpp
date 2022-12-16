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

    if (h > w)
        swap(h, w);

    int y, x;
    cin >> y >> x;

    cout << min({ y, h - y, x, w - x });
}