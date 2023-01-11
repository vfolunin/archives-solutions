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

    double x, y;
    cin >> x >> y;

    cout << (y <= 1);
    cout << (y <= -x);
    cout << (x * x + y * y <= 1);
    cout << ((x - 1) * (x - 1) + y * y <= 1);
}