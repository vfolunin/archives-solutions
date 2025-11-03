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

    double v, r1, r2;
    cin >> v >> r1 >> r2;

    cout << fixed << v * (1 + r1 / r2);
}