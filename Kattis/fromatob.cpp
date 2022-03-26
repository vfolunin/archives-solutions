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

    int a, b;
    cin >> a >> b;

    int moveCount = 0;
    while (a > b) {
        if (a % 2) {
            a++;
            moveCount++;
        }
        a /= 2;
        moveCount++;
    }
    moveCount += b - a;

    cout << moveCount;
}