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

    int r, g, b;
    cin >> r >> g >> b;

    if (r > g && r > b)
        cout << "raudur";
    else if (g > r && g > b)
        cout << "graenn";
    else if (b > r && b > g)
        cout << "blar";
    else if (r == g && r > b)
        cout << "gulur";
    else if (r == b && r > g)
        cout << "fjolubleikur";
    else if (g == b && g > r)
        cout << "blagraenn";
    else if (r == g && r == b && r == 0)
        cout << "svartur";
    else if (r == g && r == b && r == 255)
        cout << "hvitur";
    else if (r == g && r == b)
        cout << "grar";
    else
        cout << "othekkt";
}