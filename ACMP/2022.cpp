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

    int a, b, c;
    cin >> a >> b >> c;

    int z = b - c;
    int x = b - 2 * z;
    int y = a - x - z;

    cout << x << "\n" << y << "\n" << z;
}