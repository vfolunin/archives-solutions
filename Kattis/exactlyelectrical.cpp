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

    int x1, y1, x2, y2, moveCount;
    cin >> x1 >> y1 >> x2 >> y2 >> moveCount;

    moveCount -= abs(x1 - x2) + abs(y1 - y2);

    cout << (moveCount >= 0 && moveCount % 2 == 0 ? "Y\n" : "N\n");
}