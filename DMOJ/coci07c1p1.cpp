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

    int xXor = 0, yXor = 0;

    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;

        xXor ^= x;
        yXor ^= y;
    }

    cout << xXor << " " << yXor;
}