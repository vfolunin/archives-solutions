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

    long long x, y;
    cin >> x >> y;

    long long f1 = 81 * ((384000 - x) * (384000 - x) + y * y);
    long long f2 = x * x + y * y;

    if (f1 > f2)
        cout << "Earth";
    else if (f1 == f2)
        cout << "Equal";
    else
        cout << "Moon";
}