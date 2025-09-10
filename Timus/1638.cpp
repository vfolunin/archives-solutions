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

    int width, coverWidth, l, r;
    cin >> width >> coverWidth >> l >> r;

    if (l < r)
        cout << (r - l - 1) * (width + 2 * coverWidth) + 2 * coverWidth;
    else
        cout << (l - r + 1) * (width + 2 * coverWidth) - 2 * coverWidth;
}