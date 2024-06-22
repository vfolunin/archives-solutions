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
    cin >> xa >> ya >> xb >> xb >> yb;

    if (xa == xb && ya == yb)
        xb++;

    cout << xa << " " << ya << "\n" << xb << " " << yb;
}