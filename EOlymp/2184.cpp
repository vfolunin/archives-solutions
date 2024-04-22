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

    int h, w, y, x, color;
    cin >> h >> w >> y >> x >> color;

    if (h * w % 2 == 0)
        cout << "equal";
    else if ((y + x) % 2 == color)
        cout << "black";
    else
        cout << "white";
}