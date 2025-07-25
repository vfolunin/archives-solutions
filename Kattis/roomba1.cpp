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

    if (w == 1)
        cout << 0;
    else if (h == 1)
        cout << (w - 1) * 2;
    else if (h % 2 == 0 || w % 2 == 0)
        cout << h * w;
    else
        cout << h * w + 1;
}