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

    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    cout << (y1 == y2 || x1 == x2 ? 1 : 2);
}