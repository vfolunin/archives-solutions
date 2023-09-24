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

    if (h == 1 || w == 1)
        cout << 4 * h * w;
    else
        cout << 2 * (h * w + h + w - (h % 2 && w % 2));
}