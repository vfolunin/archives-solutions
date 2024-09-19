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

    int d = b * b - 4 * a * c;

    if (d > 0)
        cout << 2;
    else if (d == 0)
        cout << 1;
    else
        cout << 0;
}