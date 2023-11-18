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

    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << gcd(abs(x1 - x2), abs(y1 - y2)) + 1;
}