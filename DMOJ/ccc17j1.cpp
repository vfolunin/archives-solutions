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

    int x, y;
    cin >> x >> y;

    if (y > 0)
        cout << (x > 0 ? 1 : 2);
    else
        cout << (x < 0 ? 3 : 4);
}