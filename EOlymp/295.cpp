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

    long long radius;
    cin >> radius;

    long long res = radius;
    for (long long y = radius - 1; y > 0; y--)
        res += sqrt(radius * radius - y * y);

    cout << res * 4 + 1;
}