#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double angle;
    cin >> angle;

    int den = gcd(36000, (int)round(angle * 100));

    cout << 36000 / den << "\n";
}