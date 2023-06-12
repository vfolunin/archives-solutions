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

    int size, x, y;
    cin >> size >> x >> y;

    if (0 <= x && 0 <= y && x + y <= size)
        cout << 0;
    else if (x <= 0 && y <= 0.5 * size || x <= 0.5 * size && y <= 0)
        cout << 1;
    else if (y <= x)
        cout << 2;
    else
        cout << 3;
}