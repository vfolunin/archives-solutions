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

    if (0 <= x && x <= 432 && 0 <= y && y <= 468)
        cout << "dentro\n";
    else
        cout << "fora\n";
}