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

    if (a || !b && !c)
        cout << a;

    if (a && b > 0)
        cout << "+";
    else if (b < 0)
        cout << "-";
    if (b) {
        if (abs(b) != 1)
            cout << abs(b);
        cout << "x";
    }

    if ((a || b) && c > 0)
        cout << "+";
    else if (c < 0)
        cout << "-";
    if (c) {
        if (abs(c) != 1)
            cout << abs(c);
        cout << "y";
    }
}