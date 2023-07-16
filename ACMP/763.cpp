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

    int y, x;
    cin >> y >> x;

    if (y == 1 && x == 1)
        cout << 0;
    else if (y != x)
        cout << 1;
    else
        cout << 2;
}