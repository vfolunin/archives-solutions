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

    int a, b, c;
    cin >> a >> b >> c;

    if (a < 0)
        cout << "-";
    if (a) {
        if (abs(a) != 1)
            cout << abs(a);
        cout << "x";
    }

    if (a && b > 0)
        cout << "+";
    else if (b < 0)
        cout << "-";
    if (b) {
        if (abs(b) != 1)
            cout << abs(b);
        cout << "y";
    }

    if ((a || b) && c > 0)
        cout << "+";
    if (!a && !b || c)
        cout << c;
}