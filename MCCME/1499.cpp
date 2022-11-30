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

    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    if (xa == xb || ya == yb || xa + ya == xb + yb || xa - ya == xb - yb)
        cout << "YES";
    else
        cout << "NO";
}