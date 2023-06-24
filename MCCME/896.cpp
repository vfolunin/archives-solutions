#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int dy, dx;
    cin >> dy >> dx;

    int d = gcd(dy, dx);
    dy /= d;
    dx /= d;

    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++)
            cout << ((dy + dx) % 2 ? (y / d + x / d) % 2 : y / d % 2) << " ";
        cout << "\n";
    }
}