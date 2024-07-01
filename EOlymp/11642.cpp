#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double side;
    int n, type;
    cin >> side >> n >> type;

    for (int i = 0; i < n; i++)
        side /= sqrt(2);

    double res = type == 1 ? side * side : side * 4;

    cout << (int)(res + 1e-9);
}