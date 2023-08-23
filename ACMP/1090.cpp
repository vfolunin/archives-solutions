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

    if (x >= 0 && y >= 0)
        cout << "1 ";
    if (x <= 0 && y >= 0)
        cout << "2 ";
    if (x <= 0 && y <= 0)
        cout << "3 ";
    if (x >= 0 && y <= 0)
        cout << "4 ";
}