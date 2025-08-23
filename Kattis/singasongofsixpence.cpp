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

    double r1, r2, h, v;
    cin >> r1 >> r2 >> h >> v;

    cout << (int)((3.14159 * h * (r1 * r1 + r1 * r2 + r2 * r2) / (3 * v))) << " birds";
}