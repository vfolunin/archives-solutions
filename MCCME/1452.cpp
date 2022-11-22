#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    cout << gcd(abs(xa - xb), abs(ya - yb)) + 1;
}