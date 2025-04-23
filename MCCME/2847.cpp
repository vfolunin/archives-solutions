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

    if (!x || !y)
        cout << 0;
    else if (x > 0 && y > 0)
        cout << 1;
    else if (x < 0 && y > 0)
        cout << 2;
    else if (x < 0 && y < 0)
        cout << 3;
    else
        cout << 4;
}