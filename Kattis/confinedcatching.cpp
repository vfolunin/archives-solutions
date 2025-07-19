#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int size, xa, ya, xb, yb, x, y;
    cin >> size >> xa >> ya >> xb >> yb >> x >> y;

    do {
        if (xa != x)
            xa += xa < x ? 1 : -1;
        else
            ya += ya < y ? 1 : -1;

        if (yb != y)
            yb += yb < y ? 1 : -1;
        else
            xb += xb < x ? 1 : -1;

        cout << xa << " " << ya << " " << xb << " " << yb << endl;

        cin >> x >> y;
    } while (x || y);
}