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

    int size;
    cin >> size;

    int x = 0, y = 1;
    for (int i = 0; i < size - 1; i++) {
        int nextX = x + y;
        int nextY = y - x;
        x = nextX;
        y = nextY;
    }

    cout << x << " " << y;
}